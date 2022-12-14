#include "declaration.h"

#include <iostream>

#include "body.h"

void VarDeclaration::UpdateDepth(int depth) {
    Declaration::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_type_) p_type_->UpdateDepth(depth + 1);
    if (p_expression_) p_expression_->UpdateDepth(depth + 1);
}

void VarDeclaration::Print(std::ostream& os) const {
    Declaration::Print(os)
    if (p_ids_) p_ids->Print(os);
    if (p_type_annotation_) p_type_annotation_->Print(os);
    if (p_expression_) p_expression_->Print(os);
}

void TypeDeclaration::UpdateDepth(int depth) {
    Declaration::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_type_) p_type_->UpdateDepth(depth + 1);
}

void TypeDeclaration::Print(std::ostream& os) const {
    Declaration::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_type_) p_type_->Print(os);
}

void ProcedureDeclaration::UpdateDepth(int depth) {
    Declaration::UpdateDepth(depth);
    if (p_id_) p_id_->UpdateDepth(depth + 1);
    if (p_formal_parameters_) p_formal_parameters_->UpdateDepth(depth + 1);
    if (p_type_annotation_) p_type_annotation_->UpdateDepth(depth + 1);
    if (p_body_) p_body_->UpdateDepth(depth + 1);
}

void ProcedureDeclaration::Print(std::ostream& os) const {
    Declaration::Print(os);
    if (p_id_) p_id_->Print(os);
    if (p_formal_parameters_) p_formal_parameters_->Print(os);
    if (p_type_annotation_) p_type_annotation_->Print(os);
    if (p_body_) p_body_->Print(os);
}