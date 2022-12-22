#ifndef SRC_AST_PROGRAM_H_
#define SRC_AST_PROGRAM_H_

#include <iostream>
#include <string>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "body.h"

class Program : public Node {
    public:
        explicit Program(const yy::location& location, shared_ptr<Body> p_body)
            : Node{location,"program"}, p_body_{p_body} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;

    private:
        shared_ptr<Body> p_body_;
};

#endif  // SRC_AST_PROGRAM_H_