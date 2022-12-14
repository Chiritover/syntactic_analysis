#include "parameter.h"

#include <iostream>

void FormalParameter::UpdateDepth(int depth) {
  Node::UpdateDepth(depth);
  if (p_type_) p_type_->UpdateDepth(depth + 1);
  if (p_ids_) p_ids_->UpdateDepth(depth + 1);
}

void FormalParameter::Print(std::ostream& os) const {
  Node::Print(os);
  if (p_ids_) p_ids_->Print(os);
  if (p_type_) p_type_->Print(os);
  
}