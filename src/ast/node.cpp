#include "node.h"

#include <iostream>
#include <string>

void Node::Print(std::ostream& os) const {
    PrintBase(os);
    os << std::endl;
}

void Node::UpdateDepth(int depth) {
    SetDepth(depth);
}

void Node::PrintIndent(std::ostream& os) const {
    os << std::string(depth_, '\t');
}

void Node::PrintLocation(std::ostream& os) const {
    os << "<" << location_.begin.line << ":" << location_.begin.column << "-"
       << location_.end.line << ":" << location_.end.column << ">";
}

void Node::PrintBase(std::ostream& os) const {
    PrintIndent(os);
    os << name() << " ";
    PrintLocation(os);
}

void ValueNode::Print(std::ostream& os) const {
    PrintBase(os);
    os << " " << value() << std::endl;
}

void Nodes::Insert(shared_ptr<Node> p_node) {
    if (p_node) {
        SetLocation(loc() + p_node->loc());
        data_.push_back(p_node);
    }
}

void Nodes::InsertArray(shared_ptr<Nodes> p_nodes) {
    if (p_nodes) {
        for (auto&& p_node : p_nodes->data_) {
            Insert(p_node);
        }
    }
}

void Nodes::UpdateDepth(int depth) {
    Node::UpdateDepth(depth);
    for (auto&& p_node : data_) {
        if (p_node) p_node->UpdateDepth(depth + 1);
    }
}

void Nodes::Print(std::ostream& os) const {
    if (data_.size()) {
        Node::Print(os);
        for (const auto& p_node : data_) {
            if (p_node) p_node->Print(os);
        }
    }
}

