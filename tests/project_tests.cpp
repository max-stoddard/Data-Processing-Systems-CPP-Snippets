#include "project.hpp"
#include "relation.hpp"
#include <gtest/gtest.h>
#include <string>
#include <tuple>

using dps::Project;
using dps::Relation;

TEST(ProjectAPI, ConstructWithFunction) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "holger", "180 Queens Gate"}});

    auto proj = Project<decltype(customer), std::string>(
        customer, [](decltype(customer)::OutputType t) { return std::make_tuple(std::get<1>(t)); });

    SUCCEED(); // API compiles + constructs
}

TEST(ProjectAPI, ConstructWithMappings) {
    Relation<int, std::string, std::string> customer({"ID", "Name", "ShippingAddress"},
                                                     {{1, "holger", "180 Queens Gate"}});

    typename Project<decltype(customer), std::string>::MapSet maps = {{"Name", "customerName"}};
    auto proj = Project<decltype(customer), std::string>(customer, maps);

    SUCCEED();
}
