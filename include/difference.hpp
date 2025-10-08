#pragma once
#include <type_traits>
#include <utility>

namespace dps {

template <typename LeftInputOperator, typename RightInputOperator> struct Difference {
    using L = LeftInputOperator;
    using R = RightInputOperator;

    static_assert(std::is_same_v<typename L::OutputType, typename R::OutputType>,
                  "Difference requires identical OutputType (schema compatibility).");

    using OutputType = typename L::OutputType;

    L leftInput;
    R rightInput;

    Difference(L left, R right) : leftInput(std::move(left)), rightInput(std::move(right)) {}
};

} // namespace dps
