#include "relation.hpp"
#include "union.hpp"
#include <gtest/gtest.h>
#include <type_traits>

using dps::Relation;
using dps::Union;

TEST(Union, SchemaCompatibilityEnforced) {
    Relation<int, std::string> A({"ID", "Name"}, {{1, "A"}});
    Relation<int, std::string> B({"ID", "Name"}, {{2, "B"}});
    Union u(A, B);

    using Expected = std::tuple<int, std::string>;
    static_assert(std::is_same_v<typename decltype(u)::OutputType, Expected>);
    SUCCEED();
}
