#ifndef SRC_AST_STATEMENT_H_
#define SRC_AST_STATEMENT_H_

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "identifier.h"
#include "parameter.h"
#include "lvalue.h"

class Statement : public Node {
 public:
  explicit Statement(const yy::location& location,std::string name = "statement") : Node{location,name} {}
};

class Statements : public Nodes {
 public:
  explicit Statements(const yy::location& location, std::string name = "statement list") : Nodes{location,name} {}
};

class AssignStatement : public Statement {
    public :
        explicit AssignStatement(const yy::location& location, shared_ptr<Lvalue> p_lvalue, shared_ptr<Expression> p_expression)
        : Statement{location,"assign statement"}, p_lvalue_{p_lvalue}, p_expression_{p_expression} {}
    
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
    
    private:
        shared_ptr<Lvalue> p_lvalue_;
        shared_ptr<Expression> p_expression_;
};

class ProcedureCallStatement : public Statement {
    public:
        explicit ProcedureCallStatement(const yy::location& location,
                                         shared_ptr<Id> p_id, 
                                         shared_ptr<ActualParameters> p_actual_parameters)
        : Statement{location,"procedure call statement"}, p_id_{p_id}, p_actual_parameters_{p_actual_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Id> p_id_;
        shared_ptr<ActualParameters> p_actual_parameters_;
};

class ReadStatement : public Statement {
    public:
        explicit ReadStatement(const yy::location& location, 
                                shared_ptr<ReadParameters> p_read_parameters)
        : Statement{location,"read statement"}, p_read_parameters_{p_read_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<ReadParameters> p_read_parameters_;
};

class WriteStatement : public Statement {
    public:
        explicit WriteStatement(const yy::location& location, 
                                shared_ptr<WriteParameters> p_write_parameters)
        : Statement{location,"write statement"}, p_write_parameters_{p_write_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<WriteParameters> p_write_parameters_;
};

class ElifSection : public Node {
    public:
        explicit ElifSection(const yy::location& location, 
                                shared_ptr<Expression> p_expression, 
                                shared_ptr<Statements> p_statements)
        : Node{location,"else if section"}, p_expression_{p_expression}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Expression> p_expression_;
        shared_ptr<Statements> p_statements_;
};

class ElifSections : public Nodes {
    public:
        explicit ElifSections(const yy::location& location) : Nodes{location,"else if section list"}{}
};

class ElseSection : public Node {
    public:
        explicit ElseSection(const yy::location& location, shared_ptr<Statements> p_statements)
        :Node{location,"else section"},p_statements_{p_statements}{}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
    
    private:
        shared_ptr<Statements> p_statements_;
};

class IfStatement : public Statement {
    public:
        explicit IfStatement(const yy::location& location,
                                shared_ptr<Expression> p_expression,
                                shared_ptr<Statements> p_statements,
                                shared_ptr<ElifSections> p_elif_sections,
                                shared_ptr<ElseSection> p_else_section)
        : Statement{location,"if statement"}, p_expression_{p_expression}, p_statements_{p_statements},
        p_elif_sections_{p_elif_sections}, p_else_section_{p_else_section} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Expression> p_expression_;
        shared_ptr<Statements> p_statements_;
        shared_ptr<ElifSections> p_elif_sections_;
        shared_ptr<ElseSection> p_else_section_;
};

class WhileStatement : public Statement {
    public:
        explicit WhileStatement(const yy::location& location,
                                shared_ptr<Expression> p_expression,
                                shared_ptr<Statements> p_statements)
        : Statement{location,"while statement"}, p_expression_{p_expression}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Expression> p_expression_;
        shared_ptr<Statements> p_statements_;
};


class LoopStatement : public Statement {
    public:
        explicit LoopStatement(const yy::location& location,
                                shared_ptr<Statements> p_statements)
        : Statement{location,"loop statement"}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Statements> p_statements_;
};

class ForStep : public Node {
    public:
        explicit ForStep(const yy::location& location,
                            shared_ptr<Expression> p_expression)
        : Node{location,"for step"},p_expression_{p_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Expression> p_expression_;
};

class ForStatement : public Statement {
    public:
        explicit ForStatement(const yy::location& location,
                                shared_ptr<Id> p_id,
                                shared_ptr<Expression> p_begin,
                                shared_ptr<Expression> p_end,
                                shared_ptr<ForStep> p_for_step,
                                shared_ptr<Statements> p_statements)
        : Statement{location,"for statement"}, p_id_{p_id}, p_begin_{p_begin},
        p_end_{p_end}, p_for_step_{p_for_step}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Id> p_id_;
        shared_ptr<Expression> p_begin_;
        shared_ptr<Expression> p_end_;
        shared_ptr<ForStep> p_for_step_;
        shared_ptr<Statements> p_statements_;
};

class ExitStatement : public Statement {
    public:
        explicit ExitStatement(const yy::location& location): Statement{location,"exit statement"} {}
};

class ReturnStatement : public Statement {
    public:
        explicit ReturnStatement(const yy::location& location,
                                    shared_ptr<Expression> p_expression = nullptr)
        : Statement{location,"return statement"}, p_expression_{p_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Expression> p_expression_;
};  

#endif // SRC_AST_STATEMENT_H_