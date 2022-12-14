#include "expression.h"

#include <iostream>
#include <string>

#include "../base/common.h"
#include "parameter.h"

void NumberExpression::UpdateDepth(int depth) {
  Expression::UpdateDepth(depth);
  if (p_number_) p_number_->UpdateDepth(depth + 1);
}

void NumberExpression::Print(std::ostream& os) const {
  os << Indent(depth_) << name() << " " << value() << std::endl;
}

std::string NumberExpression::value() const {
    auto number = p_number_ ? p_number_->value() : "";
    return number;
}

void LvalueExpression::UpdateDepth(int depth) {
  Expression::UpdateDepth(depth);
  if (p_lvalue_) p_lvalue_->UpdateDepth(depth + 1);
}

void LvalueExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_lvalue_) p_lvalue_->Print(os);
}

std::string LvalueExpression::value() const {
    auto lvalue = p_lvalue_ ? p_lvalue_->value() : "";
    return lvalue;
}

void ParenthesisExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

void ParenthesisExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_expression_) p_expression_->Print(os);
}

std::string ParenthesisExpression::value() const {
    auto expression = p_expression_ ? p_expression_->value() : "";
    return "(" + expression + ")";
}

void UnaryExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_operation_) p_op_->UpdateDepth(depth + 1);
    if (p_expression_)
}

void UnaryExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_operator_) p_operator_->Print(os);
    if (p_expression_) p_expression_->Print(os);
}

std::string UnaryExpression::value() const {
    auto operator = p_operator_ ? p_operator_->value() : "";
    auto expression = p_expression_? p_expression_->value() : "";
    return operator + expression;
}

void BinaryExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_left_) p_left_->UpdateDepth(depth + 1);
    if (p_operator_) p_operator_->UpdateDepth(depth + 1);
    if (p_right_) p_right_->UpdateDepth(depth + 1);
}

void BinaryExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if(p_left_) p_left_->Print(os);
    if(p_operator_) p_operator_->Print(os);
    if(p_right_) p_right_->Print(os);
}

std::string BinaryExpression::value() const {
    auto left = p_left_ ? p_left_->value() : "";
    auto operator = p_operator_? p_operator_->value() : "";
    auto right =p_right_ ? p_right_->value() : "";

    return left + " " + operator + " " + right;
}

void ProcedureCallExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_actual_parameters_) p_actual_parameters_->UpdateDepth(depth + 1);
}

void ProcedureCallExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_actual_parameters_) p_actual_parameters_->Print(os);
}

std::string ProcedureCallExpression::value() const {
    auto id = p_id_ ? p_id_->value() : "";
    return id + "()";
}

void ComponentValues::Print(std::ostream& os) const {
    Node::print(os);
    if(p_assign_expressions_) p_assign_expressions_->Print(os);
}

void RecordConstructExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_component_values_) p_component_values_->UpdateDepth(depth + 1);
}

void RecordConstructExpression::Print(std::ostream& os) const {
    Expr::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_component_values_) p_component_values_->Print(os);
}

std::string RecordComponentExpression::value() const {
    auto id = p_id_ ? p_id_->value() : "";
    return id + "{}";
}

void ArrayValues::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    if(p_array_expressions_) p_array_expressions_->UpdateDepth(depth + 1);
}

void ArrayValues::Print(std::ostream& os) const {
    Node::Print(os);
    if (p_array_expressions_) p_array_expressions_->Print(os);
}

void ArrayConstructExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_id_) p_id->UpdateDepth(depth + 1);
    if (p_array_values_) p_array_values_->UpdateDepth(depth + 1);
}

void ArrayConstructExpression::Print(std::ostream& os) {
    Expression::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_array_values_) p_array_values_->Print(os);
}

std::string ArrayConstructExpression::value() const {
    auto id = p_id_> p_id_->value() : "";
    return id + "[<>]";
}

void WriteExpression::UpdateDepth(int depth) {
    Expression:UpdateDepth(depth);
    auto visitor = Overloaded{
        [depth](auto&& p) {
            if(p) p->UpdateDepth(depth + 1);
        },
    };
    std::visit(visitor, p_write_expression_);
}

void WriteExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    auto visitor = Overloaded{
        [&os](auto&& p){
            if (p) p->Print(os);
        },
    };
    std::visit(visitor, p_write_expression_);
}

std::string WriteExpression::value() const {
    auto visitor = Overloaded{
        [](const auto& p) {
            auto value = p ? p->value() : "";
            return value;
        },
    };
    return std::visit(visitor, p_write_expression_);
}

void AssignExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_id_) p_id_->Print(os);
    if (p_expression_) p_expression_->Print(os);
}

void AssignExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_expression_) p_expression_->Print(os);
}

std::string AssignExpression::value() const {
    auto id = p_id_ ? p_id_->value() : "";
    auto expression = p_expression_ ? p_expression_->value() : "";
    return id + " := " + expression;
}

void ArrayExpression::UpdateDepth(int depth) {
    Expression::UpdateDepth(depth);
    if (p_value_) p_value_->UpdateDepth(depth + 1);
    if (p_num_) p_num_->UpdateDepth(depth + 1);
}

void ArrayExpression::Print(std::ostream& os) const {
    Expression::Print(os);
    if (p_value_) p_value_->Print(os);
    if (p_num_) p_num_->Print(os);
}

std::string ArrayExpression::value() const {
    auto value = p_value_ ? p_value_->value() : "";
    auto num = p_num_ ? p_num_->value() + "OF" + "";
    return num + value;
}