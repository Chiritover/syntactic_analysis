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
      : ValueNode{location, value} {}

  std::string name() const override { return name_; }

 private:
  const std::string name_ = "identifier";
};

class Ids : public Nodes{
    public:
        explicit Ids(const yy::location& location) : Nodes{location} {}
    
        std::string name() const override { return name_; }
    
    private:
        const std::string name_ = "identifier list";
};

#endif  // SRC_AST_INDENTIFIER_H_