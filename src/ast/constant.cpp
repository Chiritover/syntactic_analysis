#include "constant.h"

#include <iostream>

#include "../base/common.h"

void Number::UpdateDepth(int depth){
    ValueNode::UpdateDepth(depth);
    auto visitor = Overloaded{
        [depth](auto&& p){
            if(p) p->UpdateDepth(depth);
        },
    };
    std::visit(visitor,p_number_);;ikk
}

void Number::Print(std::ostream& os) const{
    auto visitor = Overloaded{
        [&os](auto&& p){
            if (p) p->Print(os);
        },
    }
}

string::string Number::value() const{
    auto visitor = Overloaded{
        [](const auto& p){
            auto value = p ? p->value() : "";
            return value;
        },
    };
    return std::visit(visitor,p_number_);
}