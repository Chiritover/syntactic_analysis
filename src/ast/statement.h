#ifndef SRC_AST_STATEMENT_H_
#define SRC_AST_STATEMENT_H_

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
  explicit Statement(const yy::location& location) : Node{location} {}

  std::string name() const override { return name_; }

 private:
  const std::string name_ = "statement";
};

class Statements : public Nodes {
 public:
  explicit Statements(const yy::location& location) : Nodes{location} {}

  std::string name() const override { return name_; }

 private:
  const std::string name_ = "statement list";
};

class AssignStatement : public Statement {
    public :
        explicit AssignStatement(const yy::location& location, shared_ptr<Lvalue> p_lvalue, shared_ptr<Expression> p_expression)
        : Statement{location}, p_lvalue_{p_lvalue}, p_expression_{p_expression} {}
    
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "assign statement";
        shared_ptr<Lvalue> p_lvalue_;
        shared_ptr<Expression> p_expression_;
}

class ProcedureCallStatement : public Statement {
    public:
        explicit ProcedureCallStatement(const yy::location& location,
                                         shared_ptr<Id> p_id, 
                                         shared_ptr<ActualParameters> p_actual_parameters)
        : Statement{location}, p_id_{p_id}, p_actual_parameters_{p_actual_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "procedure call statement";
        shared_ptr<Id> p_id_;
        shared_ptr<ActualParameters> p_actual_parameters_;
};

class ReadStatement : public Statement {
    public:
        explicit ReadStatement(const yy::location& location, 
                                shared_ptr<ReadParameters> p_read_parameters)
        : Statement{location}, p_read_parameters_{p_read_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "read statement";
        shared_ptr<ReadParameters> p_read_parameters_;
};

class WriteStatement : public Statement {
    public:
        explicit WriteStatement(const yy::location& location, 
                                shared_ptr<WriteParameters> p_write_parameters)
        : Statement{location}, p_write_parameters_{p_write_parameters} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "write statement";
        shared_ptr<WriteParameters> p_write_parameters_;
};

class ElifSection : public Node {
    public:
        explicit ElifSection(const yy::location& location, 
                                shared_ptr<Expression> p_expression, 
                                shared_ptr<Statements> p_statements)
        : Node{location}, p_expression_{p_expression}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "else if section";
        shared_ptr<Expression> p_expression_;
        shared_ptr<Statements> p_statements_;
};

class ElifSections : public Nodes {
    public:
        explicit ElifSections(const yy:location& location) : Nodes{location}{}

        std::string name() const override {return name_;}

    private:
        const std::string name_ = "else if section list";
}

class ElseSection : public Nodes {
    public:
        explicit ElseSection(const yy:location& location, shared_ptr<Statements> p_statements)
        :Node{location},p_statements_{p_statements_}{}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override {return name_;}
    
    private:
        const std::string name_ = "else section";
        shared_ptr p_statements_;
}

class IfStatement : public Statement {
    public:
        explicit IfStatement(const yy::location& location,
                                shared_ptr<Expression> p_expression,
                                shared_ptr<Statements> p_statements,
                                shared_ptr<ElifSections> p_elif_sections,
                                shared_ptr<ElseSection> p_else_section)
        : Statement{location}, p_expression_{p_expression}, p_statements_{p_statements},
        p_elif_sections_{p_elif_sections}, p_else_section_{p_else_section} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "if statement";
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
        : Statement{location}, p_expression_{p_expression}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "while statement";
        shared_ptr<Expression> p_expression_;
        shared_ptr<Statements> p_statements_;
};


class LoopStatement : public Statement {
    public:
        explicit LoopStatement(const yy::location& location,
                                shared_ptr<Statements> p_statements)
        : Statement{location}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "loop statement";
        shared_ptr<Statements> p_statements_;
};

class ForStep : public Node {
    public:
        explicit ForStrp(const yy::location& location,
                            shared_ptr<Expression> p_expression)
        : Node{location},p_expression_{p_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "for step";
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
        : Statement{location}, p_id_{p_id}, p_begin_{p_begin},
        p_end_{p_end}, p_for_step_{p_for_step}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "for statement";
        shared_ptr<Id> p_id_;
        shared_ptr<Expression> p_begin_;
        shared_ptr<Expression> p_end_;
        shared_ptr<ForStep> p_for_step_;
        shared_ptr<Statements> p_statements_;
};

class ExitStatement : public Statement {
    public:
        explicit ExitStatement(const yy::location& location): Statement{location} {}

        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "exit statement";
};

class ReturnStatement : public Statement {
    public:
        explicit ReturnStatement(const yy::location& location,
                                    shared_ptr<Expression> p_expression)
        : Statement{location}, p_expression_{p_expression} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "return statement";
        shared_ptr<Expression> p_expression_;
};  

#endif // SRC_AST_STATEMENT_H_