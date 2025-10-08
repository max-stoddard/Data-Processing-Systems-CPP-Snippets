#pragma once
#include <set>
#include <string>
#include <tuple>
#include <utility>

namespace dps {

enum class AggregationFunction { min, max, sum, avg, count };

template <typename InputOperator, typename... Output> struct GroupedAggregation {
    using Input = InputOperator;
    using OutputType = std::tuple<Output...>;

    Input input;
    std::set<std::string> groupAttributes;
    std::set<std::tuple<std::string, AggregationFunction, std::string>> aggregations;

    GroupedAggregation(Input in, std::set<std::string> groupAttrs,
                       std::set<std::tuple<std::string, AggregationFunction, std::string>> aggs)
        : input(std::move(in)), groupAttributes(std::move(groupAttrs)),
          aggregations(std::move(aggs)) {}
};

} // namespace dps
