#include "grouped_aggregation.hpp"
#include "relation.hpp"
#include <gtest/gtest.h>
#include <set>
#include <string>
#include <tuple>

using dps::AggregationFunction;
using dps::GroupedAggregation;
using dps::Relation;

TEST(GroupedAggregation, ConstructWithGroupsAndAggs) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "Holger", "180 Queens Gate"},
                                                      {2, "Sam", "32 Vassar Street"},
                                                      {3, "Peter", "180 Queens Gate"}});

    GroupedAggregation<decltype(customer), std::string, int> ga(
        customer, {"ShippingAddress"}, {std::make_tuple("ID", AggregationFunction::count, "c")});

    using Expected = std::tuple<std::string, int>;
    static_assert(std::is_same_v<typename decltype(ga)::OutputType, Expected>);
    EXPECT_EQ(ga.groupAttributes.count("ShippingAddress"), 1u);
    EXPECT_EQ(ga.aggregations.size(), 1u);
}
