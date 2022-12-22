#ifndef SRC_AST_OPERATOR_H_
#define SRC_AST_OPERATOR_H_

#include <string>

#include "../base/common.h"
#include "../location.h"
#include "node.h"

class Operator : public ValueNode {
    public:
        explicit Operator(const yy::location& location, const std::string& value)
            : ValueNode{location,"operator", value} {}
};

#endif  // SRC_AST_OPERATOR_H_