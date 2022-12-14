#ifndef SRC_AST_TYPE_H_
#define SRC_AST_TYPE_H_

#include <iostream>
#include <string>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "identifier.h"

class Type : public Node{
    public:
        explicit Type(const yy::location& location) : Node{location} {}
    
        std::string name() const override { return name_; }
    
    private:
         std::string name_ = "type";
};

class TypeAnnotation : public Node{
    public:
        explicit TypeAnnotation(const yy::location& location, shared_ptr<Type> p_type)
            : Node{location}, p_type_{p_type} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    
    private:
        std::string name_ = "type annotation";
        shared_ptr<Type> p_type_;
};

#endif // SRC_AST_TYPE_H_