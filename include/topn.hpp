#pragma once
#include <cstddef>
#include <string>
#include <utility>

namespace dps {

template <typename InputOperator> struct TopN {
    using Input = InputOperator;
    using OutputType = typename Input::OutputType;

    Input input;
    std::size_t N;
    std::string predicate;

    TopN(Input in, std::size_t n, std::string pred)
        : input(std::move(in)), N(n), predicate(std::move(pred)) {}
};

} // namespace dps
