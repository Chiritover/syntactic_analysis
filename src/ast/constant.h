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
  explicit Constant(const yy::location& location, const T& value)
      : Node{location}, value_{value} {}

  void Print(std::ostream& os) const override {
    PrintBase(os);
    os << " " << value() << "\n";
  }

  std::string name() const override { return name_; }
  virtual T value() const { return value_; }

 private:
  const std::string name_ = "constant";
  const T value_;
};

class Integer : public Constant<std::string>{
    public:
        explicit Integer(const yy::location& location,const std::string& value) : Constant{location,value}{}
        std::string name() const override {return name_;}
    
    private:
        const std::string name_ = "integer";
};

class Real : public Constant<std::string>{
    public:
        explicit Real(const yy::location& location,const std::string& value) : Constant{location,value}{}
        std::string name() const override {return name_;}
    
    private:
        const std::string name_ = "real";
};

class Number : public ValueNode {
    public:
        using UnionPtr = std::variant<shared_ptr<Integer>, shared_ptr<Real>>;

        explicit Number(const yy::location& location, UnionPtr p_number)
            : ValueNode{location}, p_number_{p_number} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }
        std::string value() const override;
    private:
        const std::string name_ = "number";
        UnionPtr p_number_;
};

class String : public Constant<std::string> {
 public:
  explicit String(const yy::location& location, const std::string& value)
      : Constant{location, value} {}

  std::string name() const override { return name_; }

 private:
  const std::string name_ = "string";
};

#endif  // SRC_AST_CONSTANT_H_
