#include "relation.hpp"
#include "topn.hpp"
#include <gtest/gtest.h>
#include <string>
#include <tuple>

using dps::Relation;
using dps::TopN;

TEST(TopN, ConstructAndTypePreserved) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "Holger", "180 Queens Gate"},
                                                      {2, "Sam", "32 Vassar Street"},
                                                      {3, "Peter", "180 Queens Gate"}});

    TopN tn(customer, 2, "ID");

    using Expected = std::tuple<int, std::string, std::string>;
    static_assert(std::is_same_v<typename decltype(tn)::OutputType, Expected>);
    EXPECT_EQ(tn.N, 2u);
    EXPECT_EQ(tn.predicate, "ID");
}
