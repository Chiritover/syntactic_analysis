#ifndef SRC_AST_DECLARATION_H_
#define SRC_AST_DECLARATION_H_

#include <iostream>
#include <string>
#include <vector>

#include "../base/common.h"
#include "../location.h"
#include "identifier.h"
#include "node.h"
#include "parameter.h"
#include "type.h"

class Declarations;

class Declaration: public Node {
    public:
        explicit Declaration(const yy::location& location) : Node{location} {}
    
        std::string name() const override { return name_; }

    private:
        const std::string name_ = "declaration";
};

class Declarations : public Nodes {
    public:
        explicit Declarations(const yy::location& location) : Nodes{location} {}
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "declaration list";
};

class VarDeclaration : public Declaration {
    public:
        explicit VarDeclaration(const yy::location& location, 
                                shared_ptr<Ids> p_ids, 
                                shared_ptr<TypeAnnotation> p_type_annotation,
                                shared_ptr<Expression> p_expression)
            :   Declaration{location}, 
                p_ids_{p_ids}, 
                p_type_annotation_{p_type_annotation},
                p_expression_{p_expression_} {}
        
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "variable declaration";
        shared_ptr<Ids> p_ids_;
        shared_ptr<TypeAnnotation> p_type_annotation_;
        shared_ptr<Expression> p_expression_;
};

class VarDeclarations : public Declarations {
    public:
        explicit VarDeclarations(const yy::location& location) : Declarations{location} {}
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "variable declaration list";
};

class TypeDeclaration : public Declaration {
    public:
        explicit TypeDeclaration(const yy::location& location,
                                shared_ptr<Id> p_id,
                                shared_ptr<Type> p_type)
        :   Declaration{location},
            p_id_{p_id},
            p_type_{p_type} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "type declaration";
        shared_ptr<Id> p_id_;
        shared_ptr<Type> p_type_;
};

class TypeDeclarations : public Declarations {
    public:
        explicit TypeDeclarations(const yy::location& location) : Declarations{location} {}
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "type declaration list";
};

class Body;

class ProcedureDeclaration : public Declaration{
    public:
        explicit ProcedureDeclaration(const yy::location& location,
                                    shared_ptr<Id> p_id,
                                    shared_ptr<FormalParameters> p_formal_parameters,
                                    shared_ptr<TypeAnnotation> p_type_annotation,
                                    shared_ptr<Body> p_body)
        :   Declaration{location},
            p_id_{p_id},
            p_formal_parameters_{p_formal_parameters},
            p_type_annotation_{p_type_annotation},
            p_body_{p_body} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "procedure declaration";
        shared_ptr<Id> p_id_;
        shared_ptr<FormalParameters> p_formal_parameters_;
        shared_ptr<TypeAnnotation> p_type_annotation_;
        shared_ptr<Body> p_body_;
};

class ProcedureDeclarations : public Declarations {
    public:
        explicit ProcedureDeclarations(const yy::location& location) : Declarations{location} {}
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "procedure declaration list";
};

#endif  // SRC_AST_DECLARATION_H_