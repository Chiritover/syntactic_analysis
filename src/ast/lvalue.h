#ifndef SRC_AST_LVALUE_H_   
#define SRC_AST_LVALUE_H_

#include <iostream>
#include <string>
#include <vector>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "identifier.h"

class Lvalue : public ValueNode {
    public:
        explicit Lvalue(const yy::location& location) : ValueNode{location} {}

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "lvalue";
};

class Lvalues : public Nodes {
    public:
        explicit Lvalues(const yy::location& location) : Nodes{location} {}

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "lvalue list";
};

class IdLvalue : public Lvalue {
    public:
        explicit IdLvalue(const yy::location& location, shared_ptr<Id> p_id)
            : Lvalue{location}, p_id_{p_id} {}

        void UpdateDepth(int depth) override;
        std::string value() const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "lvalue";
        shared_ptr<Id> p_id_;
};

class Expression;

class ArrayElementLvalue : public Lvalue {
    public:
        explicit ArrayElementLvalue(
            const yy::location& location, shared_ptr<Lvalue> p_lvalue, shared_ptr<Expression> p_expression)
            : Lvalue{location}, p_lvalue_{p_lvalue}, p_expression_{p_expression} {}

        void UpdateDepth(int depth) override;
        std::string value() const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "lvalue";
        shared_ptr<Lvalue> p_lvalue_;
        shared_ptr<Expression> p_expression_;
};

class RecordComponentLvalue : public Lvalue {
    public:
        explicit RecordComponentLvalue(
            const yy::location& location, shared_ptr<Lvalue> p_lvalue, shared_ptr<Id> p_id)
            : Lvalue{location}, p_lvalue_{p_lvalue}, p_id_{p_id} {}

        void UpdateDepth(int depth) override;
        std::string value() const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "lvalue";
        shared_ptr<Lvalue> p_lvalue_;
        shared_ptr<Id> p_id_;
};

#endif  // SRC_AST_LVALUE_H_