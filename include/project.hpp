#pragma once
#include <functional>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <variant>

namespace dps {

template <typename InputOperator, typename... OutputTypes>
struct Project /* : public Operator<OutputTypes...> (omitted base) */ {
    using OutputType = std::tuple<OutputTypes...>;

    InputOperator input;
    using MapSet = std::set<std::pair<std::string, std::string>>; // attribute mappings
    using Func = std::function<OutputType(typename InputOperator::OutputType)>;
    std::variant<Func, MapSet> projections;

    // function-based projection
    Project(InputOperator in, Func fn) : input(in), projections(std::move(fn)) {}

    // mapping-based projection
    Project(InputOperator in, MapSet maps) : input(in), projections(std::move(maps)) {}
};

} // namespace dps
