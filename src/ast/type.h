#ifndef SRC_AST_TYPE_H_
#define SRC_AST_TYPE_H_

#include <iostream>
#include <ostream>
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

class Component : public Node {
    public:
        explicit Component(const yy::location& location, shared_ptr<Id> p_id, shared_ptr<Type> p_type)
            : Node{location}, p_id_{p_id}, p_type_{p_type} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    
    private:
        std::string name_ = "component";
        shared_ptr<Id> p_id_;
        shared_ptr<Type> p_type_;
};

class Components :public Nodes {
    public:
        explicit Components(const yy::location& location) : Nodes{location} {}

        std::string name() const override { return name_; }
    
    private:
        std::string name_ = "component list";
};

class IdType : public Type {
    public:
        explicit IdType(const yy::location& location, shared_ptr<Id> p_id)
            : Type{location}, p_id_{p_id} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    
    private:
        std::string name_ = "id type";
        shared_ptr<Id> p_id_;
};

class ArrayType : public Type {
    public:
        explicit ArrayType(const yy::location& location, shared_ptr<Type> p_type)
            : Type{location}, p_type_{p_type} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    
    private:
        std::string name_ = "array type";
        shared_ptr<Type> p_type_;
};

class RecordType : public Type {
    public:
        explicit RecordType(const yy::location& location, shared_ptr<Components> p_components)
            : Type{location}, p_components_{p_components} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os)const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "record type";
        shared_ptr<Components> p_components_;
};

#endif // SRC_AST_TYPE_H_