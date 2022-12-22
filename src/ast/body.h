#ifndef SRC_AST_BODY_H_
#define SRC_AST_BODY_H_

#include <iostream>
#include <string>

#include "../base/common.h"
#include "../location.h"
#include "node.h"
#include "declaration.h"
#include "statement.h"

class Body : public Node {
    public:
        explicit Body(
            const yy::location& location, shared_ptr<Declarations> p_declarations,shared_ptr<Statements> p_statements)
            : Node{location,"body"}, p_declarations_{p_declarations}, p_statements_{p_statements} {}

        void UpdateDepth(int depth) override;
        void Print(std::ostream& os) const override;
        
    private:
        shared_ptr<Declarations> p_declarations_;
        shared_ptr<Statements> p_statements_;
};

#endif  // SRC_AST_BODY_H_