#ifndef SRC_DRIVER_H_
#define SRC_DRIVER_H_

#include <iostream>
#include <string>

#include "ast/ast.h"
#include "base/common.h"
#include "base/config.h"
#include "lexer.h"
#include "syntactic_parser.h"

class Driver {
    public:
        Driver();

        int Paese(const std::string& in_path, const std::string& out_path);

        std::ifstream& ifs() { return *p_ifs_; }
        std::ofstream& ofs() { return *p_ofs_; }
        yy::Parser::location_type& location() { return location_; }
        void set_program(shared_ptr<Program> p_program) { p_program_ = p_program; }

    private:
        yy::Lexer lexer_;
        yy::Parser parser_;

        unique_ptr<std::ifstream> p_ifs_;
        unique_ptr<std::ofstream> p_ofs_;
        yy::Parser::location_type location_;
        shared_ptr<Program> p_program_;

        bool trace_parsing_ = LOG_LEVEL <= TRACE;
        bool trace_scanning_ = LOG_LEVEL <= TRACE;
};

#endif // SRC_DRIVER_H_