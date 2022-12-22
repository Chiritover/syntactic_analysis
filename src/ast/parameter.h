#ifndef SRC_AST_PARAMETER_H
#define SRC_AST_PARAMETER_H

#include <iostream>
#include <string>
#include <vector>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "type.h"
#include "identifier.h"
#include "expression.h"

class Parameter : public Node {
 public:
  explicit Parameter(const yy::location& location, std::string name = "parameter") : Node{location,name} {}
};

class Parameters : public Nodes {
 public:
  explicit Parameters(const yy::location& location, std::string name = "parameter list") : Nodes{location,name} {}
};

class FormalParameter : public Parameter{
    public:
        explicit FormalParameter(const yy::location& location, shared_ptr<Ids> p_ids, shared_ptr<Type> p_type)
        : Parameter{location,"formal parameter"}, p_ids_{p_ids}, p_type_{p_type} {}
    
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
    
    private:
        shared_ptr<Ids> p_ids_;
        shared_ptr<Type> p_type_;
    };

class FormalParameters : public Parameters{
    public:
        explicit FormalParameters(const yy::location& location) : Parameters{location,"formal parameter list"} {}
    };

class ActualParameters : public Expressions{
    public:
        explicit ActualParameters(const yy::location& location) : Expressions{location,"actual parameter list"} {}
    };

class ReadParameters : public Lvalues {
    public:
        explicit ReadParameters(const yy::location& location) : Lvalues{location,"read parameter list"} {}
    };

class WriteParameters : public WriteExpressions {
    public:
        explicit WriteParameters(const yy::location& location) : WriteExpressions{location,"write parameter list"} {}
    };

#endif  // SRC_AST_PARAMETER_H
