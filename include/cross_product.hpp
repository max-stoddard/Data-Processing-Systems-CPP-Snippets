#pragma once
#include "relation.hpp"
#include "tuple_utils.hpp"
#include <tuple>
#include <utility>

namespace dps {

template <typename LeftInputOperator, typename RightInputOperator> struct CrossProduct {
    using Left = LeftInputOperator;
    using Right = RightInputOperator;

    using OutputType =
        typename dps::Concat<typename Left::OutputType, typename Right::OutputType>::type;

    Left leftInput;
    Right rightInput;

    CrossProduct(Left left, Right right)
        : leftInput(std::move(left)), rightInput(std::move(right)) {}
};

} // namespace dps
