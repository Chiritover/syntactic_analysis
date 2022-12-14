#ifndef SRC_AST_NODE_H_
#define SRC_AST_NODE_H_

#include <iostream>
#include <string>
#include <vector>

#include "../base/common.h"
#include "../location.h"

class Node{
    public:
        explicit Node(const yy::location& location) : loc_{location} {}
        virtual ~Node() {}

        virtual void UpdateDepth(int depth);
        virtual void Print(std::ostream& os) const;

        virtual std::string name() const { return name_; }
        yy::location loc() const { return loc_; }
        void set_loc(const yy::location& loc) { loc_ = loc; }
        void set_depth(int depth) { depth_ = depth; }

    protected:
        void PrintIndent(std::ostream& os) const;
        void PrintLocation(std::ostream& os) const;
        void PrintBase(std::ostream& os) const;
    
    private:
        const std::string name_ = "node";
        yy::location loc_;
        int depth_ = 0;
};

class ValueNode : public Node{
    public:
        explicit ValueNode(const yy::location& location, const std::string& value = "")
            : Node{location}, value_{value} {}

        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }
        virtual std::string value() const { return value_; }

    private:
        const std::string name_ = "node";
        const std::string value_;
};

class Nodes : public Node{
    public:
        explicit Nodes(const yy::location& location) : Node{location} {}

        void Insert(shared_ptr<Node> p_node);
        void InsertArray(shared_ptr<Nodes> p_nodes);
        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

        std::string name() const override { return name_; }

    private:
        const std::string name_ = "nodes";
        std::vector<shared_ptr<Node>> data_;
};

#endif  // SRC_AST_NODE_H_  