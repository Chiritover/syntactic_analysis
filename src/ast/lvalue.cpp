#include "lvalue.h"

#include <iostream>
#include <string>

#include "expression.h"
#include "parameter.h"

void IdLvalue::UpdateDepth(int depth) {
  Lvalue::UpdateDepth(depth);
  if (p_id_) p_id_->UpdateDepth(depth + 1);
}

std::string IdLvalue::value() const {
  auto id = p_id_ ? p_id_->value() : "";
  return id;
}

void ArrayElementLvalue::UpdateDepth(int depth) {
  Lvalue::UpdateDepth(depth);
  if (p_lvalue_) p_lvalue_->UpdateDepth(depth + 1);
  if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

std::string ArrayElementLvalue::value() const {
  auto lvalue = p_lvalue_ ? p_lvalue_->value() : "";
  auto expr = p_expression_ ? p_expression_->value() : "";
  return lvalue + "[" + expr + "]";
}

void RecordComponentLvalue::UpdateDepth(int depth) {
  Lvalue::UpdateDepth(depth);
  if (p_lvalue_) p_lvalue_->UpdateDepth(depth + 1);
  if (p_id_) p_id_->UpdateDepth(depth + 1);
}

std::string RecordComponentLvalue::value() const {
  auto lvalue = p_lvalue_ ? p_lvalue_->value() : "";
  auto id = p_id_ ? p_id_->value() : "";
  return lvalue + "." + id;
}