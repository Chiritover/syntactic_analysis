#include "statement.h"

#include <iostream>

void AssignmentStatement::UpdateDepth(int depth) {
  Statement::UpdateDepth(depth);
  if (p_lvalue_) p_lvalue_->UpdateDepth(depth + 1);
  if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

void AssignmentStatement::Print(std::ostream& os) const {
  Statement::Print(os);
  if (p_lvalue_) p_lvalue_->Print(os);
  if (p_expression_) p_expression_->Print(os);
}

void ProcedureCallStatement::UpdateDepth(int depth) {
  Statement::UpdateDepth(depth);
  if (p_id_) p_id_->UpdateDepth(depth + 1);
  if (p_actual_parameters_) p_actual_parameters_->UpdateDepth(depth + 1);
}

void ProcedureCallStatement::Print(std::ostream& os) const {
  Statement::Print(os);
  if (p_id_) p_id_->Print(os);
  if (p_actual_parameters_) p_actual_parameters_->Print(os);
}

void ReadStatement::UpdateDepth(int depth) {
  Statement::UpdateDepth(depth);
  if (p_read_parameters_) p_read_parameters_->UpdateDepth(depth + 1);
}

void ReadStatement::Print(std::ostream& os) const {
  Statement::Print(os);
  if (p_read_parameters_) p_read_parameters_->Print(os);
}

void WriteStatement::UpdateDepth(int depth) {
  Statement::UpdateDepth(depth);
  if (p_write_parameters_) p_write_parameters_->UpdateDepth(depth + 1);
}

void WriteStatement::Print(std::ostream& os) const {
  Statement::Print(os);
  if (p_write_parameters_) p_write_parameters_->Print(os);
}

void IfStatement::UpdateDepth(int depth) {
    Statement::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
    if (p_else_section_) p_else_section_->UpdateDepth(depth + 1);
    if (p_elif_sections_) p_elif_sections_->UpdateDepth(depth + 1);
}

void IfStatement::Print(std::ostream& os) const {
    Statement::Print(os);
    if (p_expression_) p_expression_->Print(os);
    if (p_statements_) p_statement_->Print(os);
    if (p_elif_sections_) p_elif_sections_->Print(os);
    if (p_else_section_) p_else_section_->Print(os);
}

void ElifSection::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void ElifSection::Print(std::ostream& os) const {
    Node::Print(os);
    if (p_expression_) p_expression_->Print(os);
    if (p_statements_) p_statements_->Print(os);
}

void ElseSection::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void ElseSection::Print(std::ostream& os) const {
    Node::Print(os);
    if (p_statements_) p_statements_->Print(os);
}

void WhileStatement::UpdateDepth(int depth) {
    Statement::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void WhileStatement::Print(std::ostream& os) const {
    Statement::Print(os);
    if (p_expression_) p_expression_->Print(os);
    if (p_statements_) p_statements_->Print(os);
}

void LoopStatement::UpdateDepth(int depth) {
    Statement::UpdateDepth(depth);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void LoopStatement::Print(std::ostream& os) const {
    Statement::Print(os);
    if (p_statements_) p_statements_->Print(os);
}

void ForStatement::UpdateDepth(int depth) {
    Statement::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_begin_) p_begin_->UpdateDepth(depth + 1);
    if (p_end_) p_end_->UpdateDepth(depth + 1);
    if (p_for_step_) p_for_step_->UpdateDepth(depth + 1);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void ForStatement::Print(std::ostream& os) const {
    Statement::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_begin_) p_begin_->Print(os);
    if (p_end_) p_end_->Print(os);
    if (p_for_step_) p_for_step_->Print(os);
    if (p_statements_) p_statements_->Print(os);
}

void ForStep::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

void ForStep::Print(std::ostream& os) const {
    Node::Print(os);
    if (p_expression_) p_expression_->Print(os);
}

void ReturnStatement::UpdateDepth(int depth) {
    Statement::UpdateDepth(depth);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

void ReturnStatement::Print(std::ostream& os) const {
    Statement::Print(os);
    if (p_expression_) p_expression_->Print(os);
}


