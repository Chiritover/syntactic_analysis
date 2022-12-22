#ifndef SRC_AST_INDENTIFIER_H_
#define SRC_AST_INDENTIFIER_H_

#include <string>
#include <vector>


#include "../base/common.h"
#include "../location.h"
#include "node.h"

class Id : public ValueNode {
 public:
  explicit Id(const yy::location& location, const std::string& value)
      : ValueNode{location,"identifier", value} {}
};

class Ids : public Nodes{
    public:
        explicit Ids(const yy::location& location) : Nodes{location,"identifier list"} {}
};

#endif  // SRC_AST_INDENTIFIER_H_