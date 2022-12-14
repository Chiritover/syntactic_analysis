#ifndef SRC_AST_EXPRESSION_H_
#define SRC_AST_EXPRESSION_H_

#include<iostream>
#include<string>
#include<vector>
#include<variant>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "lvalue.h"
#include "constant.h"
#include "operator.h"
#include "identifier.h"

class Expression: public ValueNode {
    public:
        explicit Expression(const yy::location& location, const std::string& value = "")
            : ValueNode{location, value} {}
        
        std::string name() const override { return name_; }
        
    private:
        const std::string name_ = "expression";
};

class Expressions: public Nodes {
    public:
        explicit Expressions(const yy::location& location) : Nodes{location} {}
        
        std::string name() const override { return name_; }
        
    private:
        const std::string name_ = "expression list";
};

class NumberExpression : public Expression {
    public:
        explicit NumberExpression(const yy::location& location, shared_ptr<Number> p_number)
            : Expression{location}, p_number_{p_number} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "number expression";
        shared_ptr<Number> p_number_;
};

class LvalueExpression : public Expression {
    public:
        explicit LvalueExpression(const yy::location& location, shared_ptr<Lvalue> p_lvalue)
            : Expression{location}, p_lvalue_{p_lvalue} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "lvalue expression";
        shared_ptr<Lvalue> p_lvalue_;
};

class ParenthesisExpression : public Expression {
    public:
        explicit ParenthesisExpression(const yy::location& location, shared_ptr<Expression> p_expression)
            : Expression{location}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
    
    private:
        const std::string name_ = "parenthesis expression";
        shared_ptr<Expression> p_expression_;
};

class UnaryExpression : public Expression {
    public:
        explicit UnaryExpression(const yy::location& location, shared_ptr<Operator> p_operator, shared_ptr<Expression> p_expression)
            : Expression{location}, p_operator_{p_operator}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "unary expression";
        shared_ptr<Operator> p_operator_;
        shared_ptr<Expression> p_expression_;
};

class BinaryExpression : public Expression {
    public:
        explicit BinaryExpression(const yy::location& location, shared_ptr<Expression> p_left, shared_ptr<Operator> p_operator, shared_ptr<Expression> p_right)
            : Expression{location}, p_left_{p_left}, p_operator_{p_operator}, p_right_{p_right} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "binary expression";
        shared_ptr<Expression> p_left_;
        shared_ptr<Operator> p_operator_;
        shared_ptr<Expression> p_right_;
};

class ActualParameters;

class ProcedureCallExpression : public Expression {
    public:
        explicit ProcedureCallExpression(const yy::location& location, shared_ptr<Id> p_id, shared_ptr<ActualParameters> p_actual_parameters)
            : Expression{location}, p_id_{p_id}, p_actual_parameters_{p_actual_parameters} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "procedure call expression";
        shared_ptr<Id> p_id_;
        shared_ptr<ActualParameters> p_actual_parameters_;
};

class AssignExpression : public Expression {
    public:
        explicit AssignExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<Expression> p_expression)
            : Expression{location}, p_id_{p_id}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "assign expression";
        shared_ptr<Id> p_id_;
        shared_ptr<Expression> p_expression_;
};

class AssignExpressions : public Expressions{
    public:
        explicit AssignExpressions(const yy::location& location) : Expressions{location} {}

        std::string name() const override {return name_;}

    private:
        const std::string name_ = "assign expression list";
};

class ComponentValues : public Node {
    public:
        explicit ComponentValues(const yy::location& location,shared_ptr<AssignExpressions> p_assign_expressions_) : Node{location}, p_assign_expressions_{p_assign_expressions_} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    private:
        const std::string name_ = "component values";
        shared_ptr<AssignExpressions> p_assign_expressions_;
};

class ArrayExpression : public Expression {
    public:
        explicit ArrayExpression(const yy::location& location, shared_ptr<Expression> p_value, shared_ptr<Expression> p_num = nullptr)
            : Expression{location}, p_value_{p_value}, p_num_{p_num} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "array expression";
        shared_ptr<Expression> p_value_;
        shared_ptr<Expression> p_num_;
};

class ArrayExpressions : public Expressions{
    public:
        explicit ArrayExpressions(const yy::location& location) : Expressions{location} {}

        std::string name() const override {return name_;}

    private:
        const std::string name_ = "array expression list";
};

class ArrayValues : public Node {
    public:
        explicit ArrayValues(const yy::location& location,shared_ptr<ArrayExpressions> p_array_expressions_) : Node{location}, p_array_expressions_{p_array_expressions_} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
    private:
        const std::string name_ = "array values";
        shared_ptr<ArrayExpressions> p_array_expressions_;
};

class ArrayConstructExpression : public Expression {
    public:
        explicit ArrayConstructExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<ArrayValues> p_array_values)
            : Expression{location},p_id_{p_id}, p_array_values_{p_array_values} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }
        std::string value() const override;
    private:
        const std::string name_ = "array construct expression";
        shared_ptr<Id> p_id_;
        shared_ptr<ArrayValues> p_array_values_;
};
class RecordConstructExpression : public Expression {
    public:
        explicit RecordConstructExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<ComponentValues> p_component_values)
            : Expression{location},p_id_{p_id} ,p_component_values_{p_component_values} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string name() const override { return name_; }
        std::string value() const override;
        
    private:
        const std::string name_ = "record expression";
        shared_ptr<Id> p_id_;
        shared_ptr<ComponentValues> p_component_values_;
};

class WriteExpression : public Expression {
    public:
        using UnionPtr = std::variant<shared_ptr<Expression>, shared_ptr<String>>;

        explicit WriteExpression(const yy::location& location, UnionPtr p_write_expression)
            : Expression{location}, p_write_expression_{p_write_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }
        std::string value() const override;

    private:
        const std::string name_ = "write expression";
        UnionPtr p_write_expression_;
};

class WriteExpressions : public Expressions {
    public:
        explicit WriteExpressions(const yy::location& location) : Expressions{location} {}

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "write expression list";
};

#endif //SRC_AST_EXPRESSION_H_