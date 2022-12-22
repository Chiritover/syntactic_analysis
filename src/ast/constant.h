#ifndef SRC_AST_CONSTANT_H_
#define SRC_AST_CONSTANT_H_

#include <string>
#include <variant>
#include <iostream>

#include "../base/common.h"
#include "../location.h"
#include "node.h"

template <class T>
class Constant : public Node {
 public:
  explicit Constant(const yy::location& location, const T& value,std::string name = "constant")
      : Node{location,name}, value_{value} {}

  void Print(std::ostream& os) const override {
    PrintBase(os);
    os << " " << value() << "\n";
  }

  virtual T value() const { return value_; }

 private:
  const T value_;
};

class Integer : public Constant<std::string>{
    public:
        explicit Integer(const yy::location& location,const std::string& value) : Constant{location,value,"integer"}{}
};

class Real : public Constant<std::string>{
    public:
        explicit Real(const yy::location& location,const std::string& value) : Constant{location,value,"real"}{}
};

class Number : public ValueNode {
    public:
        using UnionPtr = std::variant<shared_ptr<Integer>, shared_ptr<Real>>;

        explicit Number(const yy::location& location, UnionPtr p_number)
            : ValueNode{location,"number"}, p_number_{p_number} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string value() const override;
    private:
        UnionPtr p_number_;
};

class String : public Constant<std::string> {
 public:
  explicit String(const yy::location& location, const std::string& value)
      : Constant{location, value,"string"} {}
};

#endif  // SRC_AST_CONSTANT_H_
