#include "relation.hpp"
#include <gtest/gtest.h>
#include <set>
#include <string>
#include <tuple>

using dps::Relation;

TEST(RelationBasics, ConstructAndInspect) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "holger", "180 Queens Gate"},
                                                      {2, "Sam", "32 Vassar Street"},
                                                      {3, "Peter", "180 Queens Gate"}});

    ASSERT_EQ(customer.schema.size(), 3u);
    EXPECT_EQ(customer.schema[0], "ID");
    EXPECT_EQ(customer.data.size(), 3u);

    // ensure tuples exist
    EXPECT_TRUE(customer.data.count({1, "holger", "180 Queens Gate"}) == 1);
}