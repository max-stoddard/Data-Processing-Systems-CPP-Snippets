#include "difference.hpp"
#include "relation.hpp"
#include <gtest/gtest.h>
#include <type_traits>

using dps::Difference;
using dps::Relation;

TEST(Difference, SchemaCompatibilityEnforced) {
    Relation<int, std::string> A({"ID", "Name"}, {{1, "A"}, {2, "B"}});
    Relation<int, std::string> B({"ID", "Name"}, {{2, "B"}});
    Difference d(A, B);

    using Expected = std::tuple<int, std::string>;
    static_assert(std::is_same_v<typename decltype(d)::OutputType, Expected>);
    SUCCEED();
}
