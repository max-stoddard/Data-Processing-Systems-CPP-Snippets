#include "relation.hpp"
#include "select.hpp"
#include <gtest/gtest.h>
#include <string>

using dps::Column;
using dps::Comparator;
using dps::Condition;
using dps::Relation;
using dps::Select;
using dps::Value;

TEST(SelectAPI, ConditionColumnToValue) {
    Relation<int, std::string, std::string> customer(
        {"ID", "Name", "ShippingAddress"},
        {{1, "holger", "180 Queens Gate"}, {2, "Sam", "32 Vassar Street"}});

    Condition c2v(Column("Name"), Comparator::equal, Value(std::string("Holger")));
    auto sel = Select(customer, c2v);
    SUCCEED();
}

TEST(SelectAPI, ConditionColumnToColumn) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "holger", "180 Queens Gate"}});

    Condition c2c(Column("Name"), Comparator::equal, Column("ShippingAddress"));
    auto sel = Select(customer, c2c);
    SUCCEED();
}
