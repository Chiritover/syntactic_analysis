#include "body.h"

#include <iostream>

void Body::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    if (p_declarations_) p_declarations_->UpdateDepth(depth + 1);
    if (p_statements_) p_statements_->UpdateDepth(depth + 1);
}

void Body::Print(std::ostream& os) const {
    Node::Print(os);
    if (p_declarations_) p_declarations_->Print(os);
    if (p_statements_) p_statements_->Print(os);
}