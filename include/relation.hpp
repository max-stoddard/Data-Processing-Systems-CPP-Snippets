#pragma once
#include <array>
#include <set>
#include <string>
#include <tuple>

namespace dps {

template <typename... Types> struct Relation {
    using OutputType = std::tuple<Types...>;
    std::array<std::string, sizeof...(Types)> schema;
    std::set<OutputType> data;

    Relation(std::array<std::string, sizeof...(Types)> schemaIn, std::set<OutputType> dataIn)
        : schema(schemaIn), data(std::move(dataIn)) {}
};

} // namespace dps
