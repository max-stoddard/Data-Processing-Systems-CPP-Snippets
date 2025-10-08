#pragma once
#include <string>
#include <variant>

namespace dps {

enum class Comparator { less, lessEqual, equal, greaterEqual, greater };

struct Column {
    std::string name;
    explicit Column(std::string n) : name(std::move(n)) {}
};

using Value = std::variant<std::string, int, float>;

struct Condition {
    Column leftHandSide;
    Comparator compare;
    std::variant<Column, Value> rightHandSide;
    Condition(Column lhs, Comparator cmp, std::variant<Column, Value> rhs)
        : leftHandSide(std::move(lhs)), compare(cmp), rightHandSide(std::move(rhs)) {}
};

template <typename InputOperator>
struct Select /* : public Operator<typename InputOperator::OutputType> */ {
    using OutputType = typename InputOperator::OutputType;
    InputOperator input;
    Condition condition;
    Select(InputOperator in, Condition cond) : input(in), condition(std::move(cond)) {}
};

} // namespace dps
