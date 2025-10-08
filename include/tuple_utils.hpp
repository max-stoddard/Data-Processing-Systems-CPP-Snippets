#pragma once
#include <tuple>
#include <type_traits>

namespace dps {

// Concat<std::tuple<...>, std::tuple<...>> -> std::tuple<..., ...>
template <typename T1, typename T2> struct Concat;

template <typename... L, typename... R> struct Concat<std::tuple<L...>, std::tuple<R...>> {
    using type = std::tuple<L..., R...>;
};

} // namespace dps
