#include "cross_product.hpp"
#include "relation.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <type_traits>

using dps::CrossProduct;
using dps::Relation;

TEST(CrossProduct, OutputTypeConcatenation) {
    Relation<int, int> order({"ID", "CustomerID"}, {{1, 1}, {2, 2}, {3, 3}});
    Relation<int, int> orderedItem({"OrderID", "BookID"}, {{1, 1}, {1, 2}, {2, 1}, {3, 3}});

    CrossProduct cp(order, orderedItem);

    using Expected = std::tuple<int, int, int, int>;
    static_assert(std::is_same_v<typename decltype(cp)::OutputType, Expected>,
                  "CrossProduct OutputType should be concatenation of inputs");
    SUCCEED();
}
