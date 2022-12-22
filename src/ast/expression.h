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
        explicit Expression(const yy::location& location,const std::string name = "expression", const std::string& value = "")
            : ValueNode{location,name, value} {}
};

class Expressions: public Nodes {
    public:
        explicit Expressions(const yy::location& location,const std::string name = "expression list") : Nodes{location,name} {}
};

class NumberExpression : public Expression {
    public:
        explicit NumberExpression(const yy::location& location, shared_ptr<Number> p_number)
            : Expression{location,"number expression"}, p_number_{p_number} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Number> p_number_;
};

class LvalueExpression : public Expression {
    public:
        explicit LvalueExpression(const yy::location& location, shared_ptr<Lvalue> p_lvalue)
            : Expression{location,"lvalue expression"}, p_lvalue_{p_lvalue} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Lvalue> p_lvalue_;
};

class ParenthesisExpression : public Expression {
    public:
        explicit ParenthesisExpression(const yy::location& location, shared_ptr<Expression> p_expression)
            : Expression{location,"parenthesis expression"}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
    
    private:
        shared_ptr<Expression> p_expression_;
};

class UnaryExpression : public Expression {
    public:
        explicit UnaryExpression(const yy::location& location, shared_ptr<Operator> p_operator, shared_ptr<Expression> p_expression)
            : Expression{location,"unary expression"}, p_operator_{p_operator}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Operator> p_operator_;
        shared_ptr<Expression> p_expression_;
};

class BinaryExpression : public Expression {
    public:
        explicit BinaryExpression(const yy::location& location, shared_ptr<Expression> p_left, shared_ptr<Operator> p_operator, shared_ptr<Expression> p_right)
            : Expression{location,"binary expression"}, p_left_{p_left}, p_operator_{p_operator}, p_right_{p_right} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Expression> p_left_;
        shared_ptr<Operator> p_operator_;
        shared_ptr<Expression> p_right_;
};

class ActualParameters;

class ProcedureCallExpression : public Expression {
    public:
        explicit ProcedureCallExpression(const yy::location& location, shared_ptr<Id> p_id, shared_ptr<ActualParameters> p_actual_parameters)
            : Expression{location,"procedure call expression"}, p_id_{p_id}, p_actual_parameters_{p_actual_parameters} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Id> p_id_;
        shared_ptr<ActualParameters> p_actual_parameters_;
};

class AssignExpression : public Expression {
    public:
        explicit AssignExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<Expression> p_expression)
            : Expression{location,"assign expression"}, p_id_{p_id}, p_expression_{p_expression} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
        std::string value() const override;
        
    private:
        shared_ptr<Id> p_id_;
        shared_ptr<Expression> p_expression_;
};

class AssignExpressions : public Expressions{
    public:
        explicit AssignExpressions(const yy::location& location) : Expressions{location,"assign expression list"} {}
};

class ComponentValues : public Node {
    public:
        explicit ComponentValues(const yy::location& location,shared_ptr<AssignExpressions> p_assign_expressions_,const std::string name = "component values") : Node{location,name}, p_assign_expressions_{p_assign_expressions_} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<AssignExpressions> p_assign_expressions_;
};

class ArrayExpression : public Expression {
    public:
        explicit ArrayExpression(const yy::location& location, shared_ptr<Expression> p_value, shared_ptr<Expression> p_num = nullptr)
            : Expression{location,"array expression"}, p_value_{p_value}, p_num_{p_num} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string value() const override;
        
    private:
        shared_ptr<Expression> p_value_;
        shared_ptr<Expression> p_num_;
};

class ArrayExpressions : public Expressions{
    public:
        explicit ArrayExpressions(const yy::location& location) : Expressions{location,"array expression list"} {}
};

class ArrayValues : public Node {
    public:
        explicit ArrayValues(const yy::location& location,shared_ptr<ArrayExpressions> p_array_expressions_) : Node{location, "array values"}, p_array_expressions_{p_array_expressions_} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
    private:
        shared_ptr<ArrayExpressions> p_array_expressions_;
};

class ArrayConstructExpression : public Expression {
    public:
        explicit ArrayConstructExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<ArrayValues> p_array_values)
            : Expression{location,"array construct expression"},p_id_{p_id}, p_array_values_{p_array_values} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string value() const override;
    private:
        shared_ptr<Id> p_id_;
        shared_ptr<ArrayValues> p_array_values_;
};
class RecordConstructExpression : public Expression {
    public:
        explicit RecordConstructExpression(const yy::location& location,shared_ptr<Id> p_id, shared_ptr<ComponentValues> p_component_values)
            : Expression{location,"record expression"},p_id_{p_id} ,p_component_values_{p_component_values} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string value() const override;
        
    private:
        shared_ptr<Id> p_id_;
        shared_ptr<ComponentValues> p_component_values_;
};

class WriteExpression : public Expression {
    public:
        using UnionPtr = std::variant<shared_ptr<Expression>, shared_ptr<String>>;

        explicit WriteExpression(const yy::location& location, UnionPtr p_write_expression)
            : Expression{location,"write expression"}, p_write_expression_{p_write_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string value() const override;

    private:
        UnionPtr p_write_expression_;
};

class WriteExpressions : public Expressions {
    public:
        explicit WriteExpressions(const yy::location& location,const std::string name = "write expression list") : Expressions{location,name} {}
};

#endif //SRC_AST_EXPRESSION_H_