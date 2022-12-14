// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 33 "src/syntactic_parser.yy"

    #include <memory> //for std::shared_ptr

    #include "driver.h"
    #include "lexer.h"
    #include "utils/logger.h"

    using std::make_shared;
    using location_type = yy::Parser::location_type;
    using symbol_type = yy::Parser::symbol_type;

    static symbol_tyoe yylex(yy::Lexer* p_lex) {
        return p_lex->ReadToken();
    }

    int yyFlexLexer::yylex() {
        Logger::Warning("Wrong yylex() called");
        return EXIT_FAILURE;
    }

#line 60 "src/syntactic_parser.cpp"




#include "syntactic_parser.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 159 "src/syntactic_parser.cpp"

  /// Build a parser object.
  Parser::Parser (yy::Lexer* p_lex_yyarg, Driver* p_driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      p_lex (p_lex_yyarg),
      p_driver (p_driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.YY_MOVE_OR_COPY< shared_ptr<ActualParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.YY_MOVE_OR_COPY< shared_ptr<ArrayExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.YY_MOVE_OR_COPY< shared_ptr<ArrayExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_values: // array_values
        value.YY_MOVE_OR_COPY< shared_ptr<ArrayValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.YY_MOVE_OR_COPY< shared_ptr<AssignExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.YY_MOVE_OR_COPY< shared_ptr<AssignExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_body: // body
        value.YY_MOVE_OR_COPY< shared_ptr<Body> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component: // component
        value.YY_MOVE_OR_COPY< shared_ptr<Component> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component_values: // component_values
        value.YY_MOVE_OR_COPY< shared_ptr<ComponentValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_components: // components
        value.YY_MOVE_OR_COPY< shared_ptr<Components> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.YY_MOVE_OR_COPY< shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.YY_MOVE_OR_COPY< shared_ptr<ElifSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.YY_MOVE_OR_COPY< shared_ptr<ElifSections> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_else_section: // else_section
        value.YY_MOVE_OR_COPY< shared_ptr<ElseSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.YY_MOVE_OR_COPY< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expressions: // expressions
        value.YY_MOVE_OR_COPY< shared_ptr<Expressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_step: // for_step
        value.YY_MOVE_OR_COPY< shared_ptr<ForStep> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.YY_MOVE_OR_COPY< shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.YY_MOVE_OR_COPY< shared_ptr<FormalParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.YY_MOVE_OR_COPY< shared_ptr<INTEGER> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< shared_ptr<Id> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ids: // ids
        value.YY_MOVE_OR_COPY< shared_ptr<Ids> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.YY_MOVE_OR_COPY< shared_ptr<Lvalue> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.YY_MOVE_OR_COPY< shared_ptr<Lvalues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< shared_ptr<Number> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.YY_MOVE_OR_COPY< shared_ptr<ProcedureDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.YY_MOVE_OR_COPY< shared_ptr<ProcedureDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.YY_MOVE_OR_COPY< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real: // real
        value.YY_MOVE_OR_COPY< shared_ptr<REAL> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.YY_MOVE_OR_COPY< shared_ptr<ReadParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.YY_MOVE_OR_COPY< shared_ptr<STRING> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.YY_MOVE_OR_COPY< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.YY_MOVE_OR_COPY< shared_ptr<Statements> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.YY_MOVE_OR_COPY< shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.YY_MOVE_OR_COPY< shared_ptr<TypeAnnotation> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.YY_MOVE_OR_COPY< shared_ptr<TypeDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.YY_MOVE_OR_COPY< shared_ptr<TypeDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.YY_MOVE_OR_COPY< shared_ptr<VariableDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.YY_MOVE_OR_COPY< shared_ptr<VariableDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.YY_MOVE_OR_COPY< shared_ptr<WriteExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.YY_MOVE_OR_COPY< shared_ptr<WriteExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.YY_MOVE_OR_COPY< shared_ptr<WriteParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AND: // AND
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_BEGIN: // BEGIN
      case symbol_kind::S_BY: // BY
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ELSIF: // ELSIF
      case symbol_kind::S_END: // END
      case symbol_kind::S_EXIT: // EXIT
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_IN: // IN
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_LOOP: // LOOP
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_OF: // OF
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PROCEDURE: // PROCEDURE
      case symbol_kind::S_PROGRAM: // PROGRAM
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RECORD: // RECORD
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THEN: // THEN
      case symbol_kind::S_TO: // TO
      case symbol_kind::S_TYPE: // TYPE
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_WRITE: // WRITE
      case symbol_kind::S_ASSIGN: // ":="
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GE: // ">="
      case symbol_kind::S_EQ: // "="
      case symbol_kind::S_NE: // "<>"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACK: // "["
      case symbol_kind::S_RBRACK: // "]"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_LSABRAC: // "[<"
      case symbol_kind::S_RSABRAC: // ">]"
      case symbol_kind::S_BACKSLASH: // "\\"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_STRING: // "string"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.move< shared_ptr<ActualParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.move< shared_ptr<ArrayExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.move< shared_ptr<ArrayExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_values: // array_values
        value.move< shared_ptr<ArrayValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.move< shared_ptr<AssignExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.move< shared_ptr<AssignExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_body: // body
        value.move< shared_ptr<Body> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component: // component
        value.move< shared_ptr<Component> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component_values: // component_values
        value.move< shared_ptr<ComponentValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_components: // components
        value.move< shared_ptr<Components> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.move< shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.move< shared_ptr<ElifSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.move< shared_ptr<ElifSections> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_else_section: // else_section
        value.move< shared_ptr<ElseSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expressions: // expressions
        value.move< shared_ptr<Expressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_step: // for_step
        value.move< shared_ptr<ForStep> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.move< shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.move< shared_ptr<FormalParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< shared_ptr<INTEGER> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< shared_ptr<Id> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ids: // ids
        value.move< shared_ptr<Ids> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< shared_ptr<Lvalue> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.move< shared_ptr<Lvalues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< shared_ptr<Number> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.move< shared_ptr<ProcedureDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.move< shared_ptr<ProcedureDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real: // real
        value.move< shared_ptr<REAL> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.move< shared_ptr<ReadParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.move< shared_ptr<STRING> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< shared_ptr<Statements> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.move< shared_ptr<TypeAnnotation> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< shared_ptr<TypeDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.move< shared_ptr<TypeDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< shared_ptr<VariableDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.move< shared_ptr<VariableDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.move< shared_ptr<WriteExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.move< shared_ptr<WriteExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.move< shared_ptr<WriteParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_AND: // AND
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_BEGIN: // BEGIN
      case symbol_kind::S_BY: // BY
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ELSIF: // ELSIF
      case symbol_kind::S_END: // END
      case symbol_kind::S_EXIT: // EXIT
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_IN: // IN
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_LOOP: // LOOP
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_OF: // OF
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PROCEDURE: // PROCEDURE
      case symbol_kind::S_PROGRAM: // PROGRAM
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RECORD: // RECORD
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THEN: // THEN
      case symbol_kind::S_TO: // TO
      case symbol_kind::S_TYPE: // TYPE
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_WRITE: // WRITE
      case symbol_kind::S_ASSIGN: // ":="
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GE: // ">="
      case symbol_kind::S_EQ: // "="
      case symbol_kind::S_NE: // "<>"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACK: // "["
      case symbol_kind::S_RBRACK: // "]"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_LSABRAC: // "[<"
      case symbol_kind::S_RSABRAC: // ">]"
      case symbol_kind::S_BACKSLASH: // "\\"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.copy< shared_ptr<ActualParameters> > (that.value);
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.copy< shared_ptr<ArrayExpression> > (that.value);
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.copy< shared_ptr<ArrayExpressions> > (that.value);
        break;

      case symbol_kind::S_array_values: // array_values
        value.copy< shared_ptr<ArrayValues> > (that.value);
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.copy< shared_ptr<AssignExpression> > (that.value);
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.copy< shared_ptr<AssignExpressions> > (that.value);
        break;

      case symbol_kind::S_body: // body
        value.copy< shared_ptr<Body> > (that.value);
        break;

      case symbol_kind::S_component: // component
        value.copy< shared_ptr<Component> > (that.value);
        break;

      case symbol_kind::S_component_values: // component_values
        value.copy< shared_ptr<ComponentValues> > (that.value);
        break;

      case symbol_kind::S_components: // components
        value.copy< shared_ptr<Components> > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.copy< shared_ptr<Declaration> > (that.value);
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.copy< shared_ptr<ElifSection> > (that.value);
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.copy< shared_ptr<ElifSections> > (that.value);
        break;

      case symbol_kind::S_else_section: // else_section
        value.copy< shared_ptr<ElseSection> > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.copy< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_expressions: // expressions
        value.copy< shared_ptr<Expressions> > (that.value);
        break;

      case symbol_kind::S_for_step: // for_step
        value.copy< shared_ptr<ForStep> > (that.value);
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.copy< shared_ptr<FormalParameter> > (that.value);
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.copy< shared_ptr<FormalParameters> > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.copy< shared_ptr<INTEGER> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.copy< shared_ptr<Id> > (that.value);
        break;

      case symbol_kind::S_ids: // ids
        value.copy< shared_ptr<Ids> > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< shared_ptr<Lvalue> > (that.value);
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.copy< shared_ptr<Lvalues> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.copy< shared_ptr<Number> > (that.value);
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.copy< shared_ptr<ProcedureDeclaration> > (that.value);
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.copy< shared_ptr<ProcedureDeclarations> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.copy< shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_real: // real
        value.copy< shared_ptr<REAL> > (that.value);
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.copy< shared_ptr<ReadParameters> > (that.value);
        break;

      case symbol_kind::S_string: // string
        value.copy< shared_ptr<STRING> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.copy< shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.copy< shared_ptr<Statements> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.copy< shared_ptr<Type> > (that.value);
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.copy< shared_ptr<TypeAnnotation> > (that.value);
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.copy< shared_ptr<TypeDeclaration> > (that.value);
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.copy< shared_ptr<TypeDeclarations> > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< shared_ptr<VariableDeclaration> > (that.value);
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.copy< shared_ptr<VariableDeclarations> > (that.value);
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.copy< shared_ptr<WriteExpression> > (that.value);
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.copy< shared_ptr<WriteExpressions> > (that.value);
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.copy< shared_ptr<WriteParameters> > (that.value);
        break;

      case symbol_kind::S_AND: // AND
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_BEGIN: // BEGIN
      case symbol_kind::S_BY: // BY
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ELSIF: // ELSIF
      case symbol_kind::S_END: // END
      case symbol_kind::S_EXIT: // EXIT
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_IN: // IN
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_LOOP: // LOOP
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_OF: // OF
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PROCEDURE: // PROCEDURE
      case symbol_kind::S_PROGRAM: // PROGRAM
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RECORD: // RECORD
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THEN: // THEN
      case symbol_kind::S_TO: // TO
      case symbol_kind::S_TYPE: // TYPE
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_WRITE: // WRITE
      case symbol_kind::S_ASSIGN: // ":="
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GE: // ">="
      case symbol_kind::S_EQ: // "="
      case symbol_kind::S_NE: // "<>"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACK: // "["
      case symbol_kind::S_RBRACK: // "]"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_LSABRAC: // "[<"
      case symbol_kind::S_RSABRAC: // ">]"
      case symbol_kind::S_BACKSLASH: // "\\"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_STRING: // "string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.move< shared_ptr<ActualParameters> > (that.value);
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.move< shared_ptr<ArrayExpression> > (that.value);
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.move< shared_ptr<ArrayExpressions> > (that.value);
        break;

      case symbol_kind::S_array_values: // array_values
        value.move< shared_ptr<ArrayValues> > (that.value);
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.move< shared_ptr<AssignExpression> > (that.value);
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.move< shared_ptr<AssignExpressions> > (that.value);
        break;

      case symbol_kind::S_body: // body
        value.move< shared_ptr<Body> > (that.value);
        break;

      case symbol_kind::S_component: // component
        value.move< shared_ptr<Component> > (that.value);
        break;

      case symbol_kind::S_component_values: // component_values
        value.move< shared_ptr<ComponentValues> > (that.value);
        break;

      case symbol_kind::S_components: // components
        value.move< shared_ptr<Components> > (that.value);
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.move< shared_ptr<Declaration> > (that.value);
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.move< shared_ptr<ElifSection> > (that.value);
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.move< shared_ptr<ElifSections> > (that.value);
        break;

      case symbol_kind::S_else_section: // else_section
        value.move< shared_ptr<ElseSection> > (that.value);
        break;

      case symbol_kind::S_expression: // expression
        value.move< shared_ptr<Expression> > (that.value);
        break;

      case symbol_kind::S_expressions: // expressions
        value.move< shared_ptr<Expressions> > (that.value);
        break;

      case symbol_kind::S_for_step: // for_step
        value.move< shared_ptr<ForStep> > (that.value);
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.move< shared_ptr<FormalParameter> > (that.value);
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.move< shared_ptr<FormalParameters> > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.move< shared_ptr<INTEGER> > (that.value);
        break;

      case symbol_kind::S_id: // id
        value.move< shared_ptr<Id> > (that.value);
        break;

      case symbol_kind::S_ids: // ids
        value.move< shared_ptr<Ids> > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< shared_ptr<Lvalue> > (that.value);
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.move< shared_ptr<Lvalues> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.move< shared_ptr<Number> > (that.value);
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.move< shared_ptr<ProcedureDeclaration> > (that.value);
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.move< shared_ptr<ProcedureDeclarations> > (that.value);
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (that.value);
        break;

      case symbol_kind::S_real: // real
        value.move< shared_ptr<REAL> > (that.value);
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.move< shared_ptr<ReadParameters> > (that.value);
        break;

      case symbol_kind::S_string: // string
        value.move< shared_ptr<STRING> > (that.value);
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.move< shared_ptr<Statements> > (that.value);
        break;

      case symbol_kind::S_type: // type
        value.move< shared_ptr<Type> > (that.value);
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.move< shared_ptr<TypeAnnotation> > (that.value);
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< shared_ptr<TypeDeclaration> > (that.value);
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.move< shared_ptr<TypeDeclarations> > (that.value);
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< shared_ptr<VariableDeclaration> > (that.value);
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.move< shared_ptr<VariableDeclarations> > (that.value);
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.move< shared_ptr<WriteExpression> > (that.value);
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.move< shared_ptr<WriteExpressions> > (that.value);
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.move< shared_ptr<WriteParameters> > (that.value);
        break;

      case symbol_kind::S_AND: // AND
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_BEGIN: // BEGIN
      case symbol_kind::S_BY: // BY
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ELSIF: // ELSIF
      case symbol_kind::S_END: // END
      case symbol_kind::S_EXIT: // EXIT
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_IN: // IN
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_LOOP: // LOOP
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_OF: // OF
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PROCEDURE: // PROCEDURE
      case symbol_kind::S_PROGRAM: // PROGRAM
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RECORD: // RECORD
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THEN: // THEN
      case symbol_kind::S_TO: // TO
      case symbol_kind::S_TYPE: // TYPE
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_WRITE: // WRITE
      case symbol_kind::S_ASSIGN: // ":="
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GE: // ">="
      case symbol_kind::S_EQ: // "="
      case symbol_kind::S_NE: // "<>"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACK: // "["
      case symbol_kind::S_RBRACK: // "]"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_LSABRAC: // "[<"
      case symbol_kind::S_RSABRAC: // ">]"
      case symbol_kind::S_BACKSLASH: // "\\"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_STRING: // "string"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (p_lex));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        yylhs.value.emplace< shared_ptr<ActualParameters> > ();
        break;

      case symbol_kind::S_array_expression: // array_expression
        yylhs.value.emplace< shared_ptr<ArrayExpression> > ();
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        yylhs.value.emplace< shared_ptr<ArrayExpressions> > ();
        break;

      case symbol_kind::S_array_values: // array_values
        yylhs.value.emplace< shared_ptr<ArrayValues> > ();
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        yylhs.value.emplace< shared_ptr<AssignExpression> > ();
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        yylhs.value.emplace< shared_ptr<AssignExpressions> > ();
        break;

      case symbol_kind::S_body: // body
        yylhs.value.emplace< shared_ptr<Body> > ();
        break;

      case symbol_kind::S_component: // component
        yylhs.value.emplace< shared_ptr<Component> > ();
        break;

      case symbol_kind::S_component_values: // component_values
        yylhs.value.emplace< shared_ptr<ComponentValues> > ();
        break;

      case symbol_kind::S_components: // components
        yylhs.value.emplace< shared_ptr<Components> > ();
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        yylhs.value.emplace< shared_ptr<Declaration> > ();
        break;

      case symbol_kind::S_elif_section: // elif_section
        yylhs.value.emplace< shared_ptr<ElifSection> > ();
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        yylhs.value.emplace< shared_ptr<ElifSections> > ();
        break;

      case symbol_kind::S_else_section: // else_section
        yylhs.value.emplace< shared_ptr<ElseSection> > ();
        break;

      case symbol_kind::S_expression: // expression
        yylhs.value.emplace< shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_expressions: // expressions
        yylhs.value.emplace< shared_ptr<Expressions> > ();
        break;

      case symbol_kind::S_for_step: // for_step
        yylhs.value.emplace< shared_ptr<ForStep> > ();
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        yylhs.value.emplace< shared_ptr<FormalParameter> > ();
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        yylhs.value.emplace< shared_ptr<FormalParameters> > ();
        break;

      case symbol_kind::S_integer: // integer
        yylhs.value.emplace< shared_ptr<INTEGER> > ();
        break;

      case symbol_kind::S_id: // id
        yylhs.value.emplace< shared_ptr<Id> > ();
        break;

      case symbol_kind::S_ids: // ids
        yylhs.value.emplace< shared_ptr<Ids> > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        yylhs.value.emplace< shared_ptr<Lvalue> > ();
        break;

      case symbol_kind::S_lvalues: // lvalues
        yylhs.value.emplace< shared_ptr<Lvalues> > ();
        break;

      case symbol_kind::S_number: // number
        yylhs.value.emplace< shared_ptr<Number> > ();
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        yylhs.value.emplace< shared_ptr<ProcedureDeclaration> > ();
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        yylhs.value.emplace< shared_ptr<ProcedureDeclarations> > ();
        break;

      case symbol_kind::S_program: // program
        yylhs.value.emplace< shared_ptr<Program> > ();
        break;

      case symbol_kind::S_real: // real
        yylhs.value.emplace< shared_ptr<REAL> > ();
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        yylhs.value.emplace< shared_ptr<ReadParameters> > ();
        break;

      case symbol_kind::S_string: // string
        yylhs.value.emplace< shared_ptr<STRING> > ();
        break;

      case symbol_kind::S_statement: // statement
        yylhs.value.emplace< shared_ptr<Statement> > ();
        break;

      case symbol_kind::S_statements: // statements
        yylhs.value.emplace< shared_ptr<Statements> > ();
        break;

      case symbol_kind::S_type: // type
        yylhs.value.emplace< shared_ptr<Type> > ();
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        yylhs.value.emplace< shared_ptr<TypeAnnotation> > ();
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        yylhs.value.emplace< shared_ptr<TypeDeclaration> > ();
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        yylhs.value.emplace< shared_ptr<TypeDeclarations> > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        yylhs.value.emplace< shared_ptr<VariableDeclaration> > ();
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        yylhs.value.emplace< shared_ptr<VariableDeclarations> > ();
        break;

      case symbol_kind::S_write_expression: // write_expression
        yylhs.value.emplace< shared_ptr<WriteExpression> > ();
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        yylhs.value.emplace< shared_ptr<WriteExpressions> > ();
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        yylhs.value.emplace< shared_ptr<WriteParameters> > ();
        break;

      case symbol_kind::S_AND: // AND
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_BEGIN: // BEGIN
      case symbol_kind::S_BY: // BY
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_DO: // DO
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_ELSIF: // ELSIF
      case symbol_kind::S_END: // END
      case symbol_kind::S_EXIT: // EXIT
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_IN: // IN
      case symbol_kind::S_IS: // IS
      case symbol_kind::S_LOOP: // LOOP
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_OF: // OF
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_OUT: // OUT
      case symbol_kind::S_PROCEDURE: // PROCEDURE
      case symbol_kind::S_PROGRAM: // PROGRAM
      case symbol_kind::S_READ: // READ
      case symbol_kind::S_RECORD: // RECORD
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_THEN: // THEN
      case symbol_kind::S_TO: // TO
      case symbol_kind::S_TYPE: // TYPE
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_WRITE: // WRITE
      case symbol_kind::S_ASSIGN: // ":="
      case symbol_kind::S_PLUS: // "+"
      case symbol_kind::S_MINUS: // "-"
      case symbol_kind::S_MULT: // "*"
      case symbol_kind::S_DIVIDE: // "/"
      case symbol_kind::S_LT: // "<"
      case symbol_kind::S_LE: // "<="
      case symbol_kind::S_GT: // ">"
      case symbol_kind::S_GE: // ">="
      case symbol_kind::S_EQ: // "="
      case symbol_kind::S_NE: // "<>"
      case symbol_kind::S_LPAREN: // "("
      case symbol_kind::S_RPAREN: // ")"
      case symbol_kind::S_LBRACK: // "["
      case symbol_kind::S_RBRACK: // "]"
      case symbol_kind::S_LBRACE: // "{"
      case symbol_kind::S_RBRACE: // "}"
      case symbol_kind::S_COMMA: // ","
      case symbol_kind::S_COLON: // ":"
      case symbol_kind::S_SEMICOLON: // ";"
      case symbol_kind::S_DOT: // "."
      case symbol_kind::S_LSABRAC: // "[<"
      case symbol_kind::S_RSABRAC: // ">]"
      case symbol_kind::S_BACKSLASH: // "\\"
      case symbol_kind::S_ID: // "identifier"
      case symbol_kind::S_INTEGER: // "integer"
      case symbol_kind::S_REAL: // "real"
      case symbol_kind::S_STRING: // "string"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: PROGRAM IS body ";"
#line 192 "src/syntactic_parser.yy"
                             {
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(yylhs.location,yystack_[1].value.as < shared_ptr<Body> > ());
        p_driver.SetProgram(yylhs.value.as < shared_ptr<Program> > ());
    }
#line 1723 "src/syntactic_parser.cpp"
    break;

  case 3: // program: error body ";"
#line 196 "src/syntactic_parser.yy"
                      {
        yylhs.value.as < shared_ptr<Program> > () = make_shared<Program>(yylhs.location,yystack_[1].value.as < shared_ptr<Body> > ());
        p_driver.SetProgram(yylhs.value.as < shared_ptr<Program> > ());
        yyerrok;
    }
#line 1733 "src/syntactic_parser.cpp"
    break;

  case 4: // program: error
#line 201 "src/syntactic_parser.yy"
        {yylhs.value.as < shared_ptr<Program> > () = nullptr;yyerrok;yyclearin;}
#line 1739 "src/syntactic_parser.cpp"
    break;

  case 5: // body: declarations BEGIN statements END
#line 205 "src/syntactic_parser.yy"
                                     {
        yylhs.value.as < shared_ptr<Body> > () = make_shared<Body>(yylhs.location,yystack_[3].value.as < shared_ptr<Declaration> > (),yystack_[1].value.as < shared_ptr<Statements> > ());
    }
#line 1747 "src/syntactic_parser.cpp"
    break;

  case 6: // declaration: VAR variable_declarations
#line 212 "src/syntactic_parser.yy"
                             {
        yylhs.value.as < shared_ptr<Declaration> > () = yystack_[0].value.as < shared_ptr<VariableDeclarations> > ();
        if(yylhs.value.as < shared_ptr<Declaration> > ()) yylhs.value.as < shared_ptr<Declaration> > ()->SetLocation(yylhs.location);
    }
#line 1756 "src/syntactic_parser.cpp"
    break;

  case 7: // declaration: PROCEDURE procedure_declarations
#line 216 "src/syntactic_parser.yy"
                                    {
        yylhs.value.as < shared_ptr<Declaration> > () = yystack_[0].value.as < shared_ptr<ProcedureDeclarations> > ();
        if(yylhs.value.as < shared_ptr<Declaration> > ()) yylhs.value.as < shared_ptr<Declaration> > ()->SetLocation(yylhs.location);
    }
#line 1765 "src/syntactic_parser.cpp"
    break;

  case 8: // declaration: TYPE type_declarations
#line 220 "src/syntactic_parser.yy"
                          {
        yylhs.value.as < shared_ptr<Declaration> > () = yystack_[0].value.as < shared_ptr<TypeDeclarations> > ();
        if(yylhs.value.as < shared_ptr<Declaration> > ()) yylhs.value.as < shared_ptr<Declaration> > ()->SetLocation(yylhs.location);
    }
#line 1774 "src/syntactic_parser.cpp"
    break;

  case 9: // declarations: %empty
#line 227 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<Declaration> > () = make_shared<Declarations>(yylhs.location);
    }
#line 1782 "src/syntactic_parser.cpp"
    break;

  case 10: // declarations: declarations declaration
#line 230 "src/syntactic_parser.yy"
                          {
        yylhs.value.as < shared_ptr<Declaration> > () =yystack_[1].value.as < shared_ptr<Declaration> > ();
        if(yylhs.value.as < shared_ptr<Declaration> > ()) yylhs.value.as < shared_ptr<Declaration> > ()->InsertArray(yystack_[0].value.as < shared_ptr<Declaration> > ());
    }
#line 1791 "src/syntactic_parser.cpp"
    break;

  case 11: // variable_declaration: ids type_annotation ":=" expression ";"
#line 237 "src/syntactic_parser.yy"
                                                   {
        yylhs.value.as < shared_ptr<VariableDeclaration> > () = make_shared<VariableDeclaration>(yylhs.location,yystack_[4].value.as < shared_ptr<Ids> > (),yystack_[3].value.as < shared_ptr<TypeAnnotation> > (),yystack_[1].value.as < shared_ptr<Expression> > ());
    }
#line 1799 "src/syntactic_parser.cpp"
    break;

  case 12: // variable_declaration: error ";"
#line 240 "src/syntactic_parser.yy"
                 {
    yylhs.value.as < shared_ptr<VariableDeclaration> > () = nullptr;
    yyerrok;
    }
#line 1808 "src/syntactic_parser.cpp"
    break;

  case 13: // variable_declarations: variable_declaration
#line 247 "src/syntactic_parser.yy"
                        {
        yylhs.value.as < shared_ptr<VariableDeclarations> > () = make_shared<VariableDeclarations>(yylhs.location);
        if(yylhs.value.as < shared_ptr<VariableDeclarations> > ()) yylhs.value.as < shared_ptr<VariableDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<VariableDeclaration> > ());
    }
#line 1817 "src/syntactic_parser.cpp"
    break;

  case 14: // variable_declarations: variable_declarations variable_declaration
#line 251 "src/syntactic_parser.yy"
                                             {
        yylhs.value.as < shared_ptr<VariableDeclarations> > () = yystack_[1].value.as < shared_ptr<VariableDeclarations> > ();
        if(yylhs.value.as < shared_ptr<VariableDeclarations> > ()) yylhs.value.as < shared_ptr<VariableDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<VariableDeclaration> > ());
    }
#line 1826 "src/syntactic_parser.cpp"
    break;

  case 15: // type_declaration: id IS type ";"
#line 258 "src/syntactic_parser.yy"
                        {
        yylhs.value.as < shared_ptr<TypeDeclaration> > () = make_shared<TypeDeclaration>(yylhs.location,yystack_[3].value.as < shared_ptr<Id> > (),yystack_[1].value.as < shared_ptr<Type> > ());
    }
#line 1834 "src/syntactic_parser.cpp"
    break;

  case 16: // type_declaration: error ";"
#line 261 "src/syntactic_parser.yy"
                 {yylhs.value.as < shared_ptr<TypeDeclaration> > () = nullptr;yyerrok;}
#line 1840 "src/syntactic_parser.cpp"
    break;

  case 17: // type_declarations: type_declaration
#line 265 "src/syntactic_parser.yy"
                     {
        yylhs.value.as < shared_ptr<TypeDeclarations> > () = make_shared<TypeDeclaration>(yylhs.location);
        if(yylhs.value.as < shared_ptr<TypeDeclarations> > ()){
            yylhs.value.as < shared_ptr<TypeDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<TypeDeclaration> > ());
        }
    }
#line 1851 "src/syntactic_parser.cpp"
    break;

  case 18: // type_declarations: type_declarations type_declaration
#line 271 "src/syntactic_parser.yy"
                                      {
        yylhs.value.as < shared_ptr<TypeDeclarations> > () = yystack_[1].value.as < shared_ptr<TypeDeclarations> > ();
        if(yylhs.value.as < shared_ptr<TypeDeclarations> > ()){
            yylhs.value.as < shared_ptr<TypeDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<TypeDeclaration> > ());
        }
    }
#line 1862 "src/syntactic_parser.cpp"
    break;

  case 19: // procedure_declaration: id "(" formal_parameters ")" type_annotation IS body ";"
#line 280 "src/syntactic_parser.yy"
                                                                        {
        yylhs.value.as < shared_ptr<ProcedureDeclaration> > () = make_shared<ProcedureDeclaration>(yylhs.location,yystack_[7].value.as < shared_ptr<Id> > (),yystack_[5].value.as < shared_ptr<FormalParameters> > (),yystack_[3].value.as < shared_ptr<TypeAnnotation> > (),yystack_[1].value.as < shared_ptr<Body> > ());
    }
#line 1870 "src/syntactic_parser.cpp"
    break;

  case 20: // procedure_declaration: id "(" formal_parameters ")" type_annotation error body ";"
#line 283 "src/syntactic_parser.yy"
                                                                           {
        yylhs.value.as < shared_ptr<ProcedureDeclaration> > () = make_shared<ProcedureDeclaration>(yylhs.location,yystack_[7].value.as < shared_ptr<Id> > (),yystack_[5].value.as < shared_ptr<FormalParameters> > (),yystack_[3].value.as < shared_ptr<TypeAnnotation> > (),yystack_[1].value.as < shared_ptr<Body> > ());
        yyerrok;
    }
#line 1879 "src/syntactic_parser.cpp"
    break;

  case 21: // procedure_declarations: procedure_declaration
#line 290 "src/syntactic_parser.yy"
                         {
        yylhs.value.as < shared_ptr<ProcedureDeclarations> > () = make_shared<ProcedureDeclarations>(yylhs.location);
        if(yylhs.value.as < shared_ptr<ProcedureDeclarations> > ()){
            yylhs.value.as < shared_ptr<ProcedureDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<ProcedureDeclaration> > ());
        }
    }
#line 1890 "src/syntactic_parser.cpp"
    break;

  case 22: // procedure_declarations: procedure_declarations procedure_declaration
#line 297 "src/syntactic_parser.yy"
                                                {
        yylhs.value.as < shared_ptr<ProcedureDeclarations> > () = yystack_[1].value.as < shared_ptr<ProcedureDeclarations> > ();
        if(yylhs.value.as < shared_ptr<ProcedureDeclarations> > ()){
            yylhs.value.as < shared_ptr<ProcedureDeclarations> > ()->Insert(yystack_[0].value.as < shared_ptr<ProcedureDeclaration> > ());
        }
    }
#line 1901 "src/syntactic_parser.cpp"
    break;

  case 23: // formal_parameter: ids ":" type
#line 306 "src/syntactic_parser.yy"
                  {
        yylhs.value.as < shared_ptr<FormalParameter> > () = make_shared<FormalParameter>(yylhs.location,yystack_[2].value.as < shared_ptr<Ids> > (),yystack_[0].value.as < shared_ptr<Type> > ());
    }
#line 1909 "src/syntactic_parser.cpp"
    break;

  case 24: // formal_parameters: %empty
#line 312 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<FormalParameters> > () = make_shared<FormalParameters>(yylhs.location);
    }
#line 1917 "src/syntactic_parser.cpp"
    break;

  case 25: // formal_parameters: formal_parameter
#line 315 "src/syntactic_parser.yy"
                    {
        yylhs.value.as < shared_ptr<FormalParameters> > () = make_shared<FormalParameters>(yylhs.location);
        if(yylhs.value.as < shared_ptr<FormalParameters> > ()){
            yylhs.value.as < shared_ptr<FormalParameters> > ()->Insert(yystack_[0].value.as < shared_ptr<FormalParameter> > ());
        }
    }
#line 1928 "src/syntactic_parser.cpp"
    break;

  case 26: // formal_parameters: formal_parameters ";" formal_parameter
#line 321 "src/syntactic_parser.yy"
                                                {
        yylhs.value.as < shared_ptr<FormalParameters> > () = yystack_[2].value.as < shared_ptr<FormalParameters> > ();
        if(yylhs.value.as < shared_ptr<FormalParameters> > ()){
            yylhs.value.as < shared_ptr<FormalParameters> > ()->Insert(yystack_[0].value.as < shared_ptr<FormalParameter> > ());
        }
    }
#line 1939 "src/syntactic_parser.cpp"
    break;

  case 27: // type: id
#line 330 "src/syntactic_parser.yy"
      {
        yylhs.value.as < shared_ptr<Type> > () = make_shared<IdType>(yylhs.location,yystack_[0].value.as < shared_ptr<Id> > ());
    }
#line 1947 "src/syntactic_parser.cpp"
    break;

  case 28: // type: ARRAY OF type
#line 333 "src/syntactic_parser.yy"
                           {
        yylhs.value.as < shared_ptr<Type> > () = make_shared<ArrayType>(yylhs.location,yystack_[0].value.as < shared_ptr<Type> > ());
    }
#line 1955 "src/syntactic_parser.cpp"
    break;

  case 29: // type: RECORD components END
#line 336 "src/syntactic_parser.yy"
                          {
        yylhs.value.as < shared_ptr<Type> > () = make_shared<RecordType>(yylhs.location,yystack_[1].value.as < shared_ptr<Components> > ()); 
    }
#line 1963 "src/syntactic_parser.cpp"
    break;

  case 30: // type_annotation: ":" type
#line 342 "src/syntactic_parser.yy"
              {
        yylhs.value.as < shared_ptr<TypeAnnotation> > () = make_shared<TypeAnnotation>(yylhs.location,yystack_[0].value.as < shared_ptr<Type> > ());
    }
#line 1971 "src/syntactic_parser.cpp"
    break;

  case 31: // type_annotation: %empty
#line 345 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<TypeAnnotation> > () = nullptr;
    }
#line 1979 "src/syntactic_parser.cpp"
    break;

  case 32: // component: id ":" type ";"
#line 351 "src/syntactic_parser.yy"
                           {
        yylhs.value.as < shared_ptr<Component> > () = make_shared<Component>(yylhs.location,yystack_[3].value.as < shared_ptr<Id> > (),yystack_[1].value.as < shared_ptr<Type> > ());
    }
#line 1987 "src/syntactic_parser.cpp"
    break;

  case 33: // component: error ";"
#line 354 "src/syntactic_parser.yy"
                    { yylhs.value.as < shared_ptr<Component> > () = nullptr; yyerrok;}
#line 1993 "src/syntactic_parser.cpp"
    break;

  case 34: // components: component
#line 359 "src/syntactic_parser.yy"
             {
        yylhs.value.as < shared_ptr<Components> > () = make_shared<Components>(yylhs.location); if(yylhs.value.as < shared_ptr<Components> > ()) yylhs.value.as < shared_ptr<Components> > ()->Insert(yystack_[0].value.as < shared_ptr<Component> > ());
    }
#line 2001 "src/syntactic_parser.cpp"
    break;

  case 35: // components: components component
#line 362 "src/syntactic_parser.yy"
                          {
        yylhs.value.as < shared_ptr<Components> > () = yystack_[1].value.as < shared_ptr<Components> > (); if(yylhs.value.as < shared_ptr<Components> > ()) yylhs.value.as < shared_ptr<Components> > ()->Insert(yystack_[0].value.as < shared_ptr<Component> > ());
    }
#line 2009 "src/syntactic_parser.cpp"
    break;

  case 36: // id: "identifier"
#line 368 "src/syntactic_parser.yy"
      {
    yylhs.value.as < shared_ptr<Id> > () = make_shared<Id>(yylhs.location,yystack_[0].value.as < std::string > ());
}
#line 2017 "src/syntactic_parser.cpp"
    break;

  case 37: // ids: id
#line 374 "src/syntactic_parser.yy"
       {
        yylhs.value.as < shared_ptr<Ids> > () = make_shared<Id>(yylhs.location,yystack_[0].value.as < shared_ptr<Id> > ()); 
    }
#line 2025 "src/syntactic_parser.cpp"
    break;

  case 38: // ids: ids "," id
#line 377 "src/syntactic_parser.yy"
                 {
        yylhs.value.as < shared_ptr<Ids> > () = yystack_[2].value.as < shared_ptr<Ids> > (); if(yylhs.value.as < shared_ptr<Ids> > ()) yylhs.value.as < shared_ptr<Ids> > ()->Insert(yystack_[0].value.as < shared_ptr<Id> > ());
    }
#line 2033 "src/syntactic_parser.cpp"
    break;

  case 39: // statement: lvalue ":=" expression ";"
#line 386 "src/syntactic_parser.yy"
                                      {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<AssignStatement>(yylhs.location,yystack_[3].value.as < shared_ptr<Lvalue> > (),yystack_[1].value.as < shared_ptr<Expression> > ());
    }
#line 2041 "src/syntactic_parser.cpp"
    break;

  case 40: // statement: id "(" actual_parameters ")" ";"
#line 389 "src/syntactic_parser.yy"
                                                {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<CallStatement>(yylhs.location,yystack_[4].value.as < shared_ptr<Id> > (),yystack_[2].value.as < shared_ptr<ActualParameters> > ());
    }
#line 2049 "src/syntactic_parser.cpp"
    break;

  case 41: // statement: IF expression THEN statements elif_sections else_section END ";"
#line 392 "src/syntactic_parser.yy"
                                                                                      {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<IfStatement>(yylhs.location,yystack_[6].value.as < shared_ptr<Expression> > (),yystack_[4].value.as < shared_ptr<Statements> > (),yystack_[3].value.as < shared_ptr<ElifSections> > (),yystack_[2].value.as < shared_ptr<ElseSection> > ());
    }
#line 2057 "src/syntactic_parser.cpp"
    break;

  case 42: // statement: READ "(" read_parameters ")" ";"
#line 395 "src/syntactic_parser.yy"
                                                {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<ReadStatement>(yylhs.location,yystack_[2].value.as < shared_ptr<ReadParameters> > ());
    }
#line 2065 "src/syntactic_parser.cpp"
    break;

  case 43: // statement: WRITE "(" write_parameters ")" ";"
#line 398 "src/syntactic_parser.yy"
                                                  {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<WriteStatement>(yylhs.location,yystack_[2].value.as < shared_ptr<WriteParameters> > ());
    }
#line 2073 "src/syntactic_parser.cpp"
    break;

  case 44: // statement: WHILE expression DO statements END ";"
#line 401 "src/syntactic_parser.yy"
                                                {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<WhileStatement>(yylhs.location,yystack_[4].value.as < shared_ptr<Expression> > (),yystack_[2].value.as < shared_ptr<Statements> > ());
    }
#line 2081 "src/syntactic_parser.cpp"
    break;

  case 45: // statement: LOOP statements END ";"
#line 404 "src/syntactic_parser.yy"
                                 {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<LoopStatement>(yylhs.location,yystack_[2].value.as < shared_ptr<Statements> > ());
    }
#line 2089 "src/syntactic_parser.cpp"
    break;

  case 46: // statement: FOR id ":=" expression TO expression for_step DO statements END ";"
#line 407 "src/syntactic_parser.yy"
                                                                                                 {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<ForStatement>(yylhs.location,yystack_[9].value.as < shared_ptr<Id> > (),yystack_[7].value.as < shared_ptr<Expression> > (),yystack_[5].value.as < shared_ptr<Expression> > (),yystack_[4].value.as < shared_ptr<ForStep> > (),yystack_[2].value.as < shared_ptr<Statements> > ());
    }
#line 2097 "src/syntactic_parser.cpp"
    break;

  case 47: // statement: RETURN expression ";"
#line 410 "src/syntactic_parser.yy"
                               {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<ReturnStatement>(yylhs.location,yystack_[1].value.as < shared_ptr<Expression> > ());
    }
#line 2105 "src/syntactic_parser.cpp"
    break;

  case 48: // statement: RETURN ";"
#line 413 "src/syntactic_parser.yy"
                    {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<ReturnStatement>(yylhs.location);
    }
#line 2113 "src/syntactic_parser.cpp"
    break;

  case 49: // statement: EXIT ";"
#line 417 "src/syntactic_parser.yy"
                  {
        yylhs.value.as < shared_ptr<Statement> > () = make_shared<ExitStatement>(yylhs.location);
    }
#line 2121 "src/syntactic_parser.cpp"
    break;

  case 50: // statement: error ";"
#line 420 "src/syntactic_parser.yy"
                   {
        yylhs.value.as < shared_ptr<Statement> > () = nullptr;
        yyerrok;
    }
#line 2130 "src/syntactic_parser.cpp"
    break;

  case 51: // statements: %empty
#line 427 "src/syntactic_parser.yy"
           {
        yylhs.value.as < shared_ptr<Statements> > () = make_shared<Statements>(yylhs.location);
    }
#line 2138 "src/syntactic_parser.cpp"
    break;

  case 52: // statements: statements statement
#line 430 "src/syntactic_parser.yy"
                         {
        yylhs.value.as < shared_ptr<Statements> > () = yystack_[1].value.as < shared_ptr<Statements> > (); if(yylhs.value.as < shared_ptr<Statements> > ()) yylhs.value.as < shared_ptr<Statements> > ()->Insert(yystack_[0].value.as < shared_ptr<Statement> > ());
    }
#line 2146 "src/syntactic_parser.cpp"
    break;

  case 53: // actual_parameters: %empty
#line 436 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<ActualParameters> > () = make_shared<ActualParameters>(yylhs.location);
    }
#line 2154 "src/syntactic_parser.cpp"
    break;

  case 54: // actual_parameters: expressions
#line 439 "src/syntactic_parser.yy"
               {
        yylhs.value.as < shared_ptr<ActualParameters> > () = make_shared<ActualParameters>(yylhs.location);
        if(yylhs.value.as < shared_ptr<ActualParameters> > ()){
            yylhs.value.as < shared_ptr<ActualParameters> > ()->InsertArray(yystack_[0].value.as < shared_ptr<Expressions> > ());
        }
    }
#line 2165 "src/syntactic_parser.cpp"
    break;

  case 55: // read_parameters: lvalues
#line 448 "src/syntactic_parser.yy"
            {
        yylhs.value.as < shared_ptr<ReadParameters> > () = make_shared<ReadParameters>(yylhs.location);
        if(yylhs.value.as < shared_ptr<ReadParameters> > ()){
            yylhs.value.as < shared_ptr<ReadParameters> > ()->InsertArray(yystack_[0].value.as < shared_ptr<Lvalues> > ());
        }
    }
#line 2176 "src/syntactic_parser.cpp"
    break;

  case 56: // write_parameters: write_expressions
#line 457 "src/syntactic_parser.yy"
                      {
        yylhs.value.as < shared_ptr<WriteParameters> > () = make_shared<WriteParameters>(yylhs.location);
        if(yylhs.value.as < shared_ptr<WriteParameters> > ()){
            yylhs.value.as < shared_ptr<WriteParameters> > ()->InsertArray(yystack_[0].value.as < shared_ptr<WriteExpressions> > ());
        }
    }
#line 2187 "src/syntactic_parser.cpp"
    break;

  case 57: // write_parameters: %empty
#line 463 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<WriteParameters> > () = make_shared<WriteParameters>(yylhs.location);
    }
#line 2195 "src/syntactic_parser.cpp"
    break;

  case 58: // elif_section: ELSIF expression THEN statements
#line 469 "src/syntactic_parser.yy"
                                    {
        yylhs.value.as < shared_ptr<ElifSection> > () = make_shared<ElifSection>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),yystack_[0].value.as < shared_ptr<Statements> > ());
    }
#line 2203 "src/syntactic_parser.cpp"
    break;

  case 59: // elif_sections: %empty
#line 475 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<ElifSections> > () = make_shared<ElifSections>(yylhs.location);
    }
#line 2211 "src/syntactic_parser.cpp"
    break;

  case 60: // elif_sections: elif_sections elif_section
#line 478 "src/syntactic_parser.yy"
                              {
        yylhs.value.as < shared_ptr<ElifSections> > () = yystack_[1].value.as < shared_ptr<ElifSections> > ();
        if(yylhs.value.as < shared_ptr<ElifSections> > ()){
            yylhs.value.as < shared_ptr<ElifSections> > ()->Insert(yystack_[0].value.as < shared_ptr<ElifSection> > ());
        }
    }
#line 2222 "src/syntactic_parser.cpp"
    break;

  case 61: // else_section: %empty
#line 487 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<ElseSection> > () = nullptr;
    }
#line 2230 "src/syntactic_parser.cpp"
    break;

  case 62: // else_section: ELSE statements
#line 490 "src/syntactic_parser.yy"
                   {
        yylhs.value.as < shared_ptr<ElseSection> > () = make_shared<ElseSection>(yylhs.location,yystack_[0].value.as < shared_ptr<Statements> > ());
    }
#line 2238 "src/syntactic_parser.cpp"
    break;

  case 63: // for_step: %empty
#line 496 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<ForStep> > () = nullptr;
    }
#line 2246 "src/syntactic_parser.cpp"
    break;

  case 64: // for_step: BY expression
#line 499 "src/syntactic_parser.yy"
                 {
        yylhs.value.as < shared_ptr<ForStep> > () = make_shared<ForStep>(yylhs.location,yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2254 "src/syntactic_parser.cpp"
    break;

  case 65: // expression: lvalue
#line 507 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<LvalueExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<Lvalue> > ());
    }
#line 2262 "src/syntactic_parser.cpp"
    break;

  case 66: // expression: number
#line 510 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<NumberExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<Number> > ());
    }
#line 2270 "src/syntactic_parser.cpp"
    break;

  case 67: // expression: "(" expression ")"
#line 513 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<ParenExpression>(yylhs.location,yystack_[1].value.as < shared_ptr<Expression> > ());
    }
#line 2278 "src/syntactic_parser.cpp"
    break;

  case 68: // expression: "+" expression
#line 516 "src/syntactic_parser.yy"
                             { 
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yylhs.location,make_shared<Op>(yystack_[1].location, yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2286 "src/syntactic_parser.cpp"
    break;

  case 69: // expression: "-" expression
#line 519 "src/syntactic_parser.yy"
                              {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yylhs.location,make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2294 "src/syntactic_parser.cpp"
    break;

  case 70: // expression: NOT expression
#line 522 "src/syntactic_parser.yy"
                  {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<UnaryExpression>(yylhs.location,make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2302 "src/syntactic_parser.cpp"
    break;

  case 71: // expression: expression "+" expression
#line 525 "src/syntactic_parser.yy"
                               {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2310 "src/syntactic_parser.cpp"
    break;

  case 72: // expression: expression "-" expression
#line 528 "src/syntactic_parser.yy"
                               {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2318 "src/syntactic_parser.cpp"
    break;

  case 73: // expression: expression "*" expression
#line 531 "src/syntactic_parser.yy"
                              {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2326 "src/syntactic_parser.cpp"
    break;

  case 74: // expression: expression DIV expression
#line 534 "src/syntactic_parser.yy"
                             {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2334 "src/syntactic_parser.cpp"
    break;

  case 75: // expression: expression "/" expression
#line 537 "src/syntactic_parser.yy"
                                {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2342 "src/syntactic_parser.cpp"
    break;

  case 76: // expression: expression MOD expression
#line 540 "src/syntactic_parser.yy"
                             {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2350 "src/syntactic_parser.cpp"
    break;

  case 77: // expression: expression AND expression
#line 543 "src/syntactic_parser.yy"
                             {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2358 "src/syntactic_parser.cpp"
    break;

  case 78: // expression: expression OR expression
#line 546 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2366 "src/syntactic_parser.cpp"
    break;

  case 79: // expression: expression "=" expression
#line 549 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2374 "src/syntactic_parser.cpp"
    break;

  case 80: // expression: expression "<>" expression
#line 552 "src/syntactic_parser.yy"
                           {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2382 "src/syntactic_parser.cpp"
    break;

  case 81: // expression: expression "<" expression
#line 555 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2390 "src/syntactic_parser.cpp"
    break;

  case 82: // expression: expression "<=" expression
#line 558 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2398 "src/syntactic_parser.cpp"
    break;

  case 83: // expression: expression ">" expression
#line 561 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2406 "src/syntactic_parser.cpp"
    break;

  case 84: // expression: expression ">=" expression
#line 564 "src/syntactic_parser.yy"
                            {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<BinaryExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Expression> > (),make_shared<Op>(yystack_[1].location,yystack_[1].value.as < std::string > ()),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2414 "src/syntactic_parser.cpp"
    break;

  case 85: // expression: id "(" actual_parameters ")"
#line 567 "src/syntactic_parser.yy"
                                      {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<ProcCallExpression>(yylhs.location,yystack_[3].value.as < shared_ptr<Id> > (),yystack_[1].value.as < shared_ptr<ActualParameters> > ());
    }
#line 2422 "src/syntactic_parser.cpp"
    break;

  case 86: // expression: id "{" component_values "}"
#line 570 "src/syntactic_parser.yy"
                                     {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<RecordConstrExpression>(yylhs.location,yystack_[3].value.as < shared_ptr<Id> > (),yystack_[1].value.as < shared_ptr<ComponentValues> > ());
    }
#line 2430 "src/syntactic_parser.cpp"
    break;

  case 87: // expression: id "[<" array_values ">]"
#line 573 "src/syntactic_parser.yy"
                                   {
        yylhs.value.as < shared_ptr<Expression> > () = make_shared<ArrayConstrExpression>(yylhs.location,yystack_[3].value.as < shared_ptr<Id> > (),yystack_[1].value.as < shared_ptr<ArrayValues> > ());
    }
#line 2438 "src/syntactic_parser.cpp"
    break;

  case 88: // expressions: expression
#line 579 "src/syntactic_parser.yy"
              {
        yylhs.value.as < shared_ptr<Expressions> > () = make_shared<Expressions>(yylhs.location);
        if(yylhs.value.as < shared_ptr<Expressions> > ()){
            yylhs.value.as < shared_ptr<Expressions> > ()->Insert(yystack_[0].value.as < shared_ptr<Expression> > ());
        }
    }
#line 2449 "src/syntactic_parser.cpp"
    break;

  case 89: // expressions: expressions "," expression
#line 585 "src/syntactic_parser.yy"
                                {
        yylhs.value.as < shared_ptr<Expressions> > () = yystack_[2].value.as < shared_ptr<Expressions> > ();
        if(yylhs.value.as < shared_ptr<Expressions> > ()){
            yylhs.value.as < shared_ptr<Expressions> > ()->Insert(yystack_[0].value.as < shared_ptr<Expression> > ());
        }
    }
#line 2460 "src/syntactic_parser.cpp"
    break;

  case 90: // write_expression: expression
#line 594 "src/syntactic_parser.yy"
              {
        yylhs.value.as < shared_ptr<WriteExpression> > () = make_shared<WriteExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2468 "src/syntactic_parser.cpp"
    break;

  case 91: // write_expression: string
#line 597 "src/syntactic_parser.yy"
            {
        yylhs.value.as < shared_ptr<WriteExpression> > () = make_shared<WriteExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<STRING> > ());
    }
#line 2476 "src/syntactic_parser.cpp"
    break;

  case 92: // write_expressions: write_expression
#line 603 "src/syntactic_parser.yy"
                    {
        yylhs.value.as < shared_ptr<WriteExpressions> > () = make_shared<WriteExpressions>(yylhs.location);
        if(yylhs.value.as < shared_ptr<WriteExpressions> > ()){
            yylhs.value.as < shared_ptr<WriteExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<WriteExpression> > ());
        }
    }
#line 2487 "src/syntactic_parser.cpp"
    break;

  case 93: // write_expressions: write_expressions "," write_expression
#line 609 "src/syntactic_parser.yy"
                                            {
        yylhs.value.as < shared_ptr<WriteExpressions> > () = yystack_[2].value.as < shared_ptr<WriteExpressions> > ();
        if(yylhs.value.as < shared_ptr<WriteExpressions> > ()){
            yylhs.value.as < shared_ptr<WriteExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<WriteExpression> > ());
        }
    }
#line 2498 "src/syntactic_parser.cpp"
    break;

  case 94: // assign_expression: id ":=" expression
#line 618 "src/syntactic_parser.yy"
                        {
        yylhs.value.as < shared_ptr<AssignExpression> > () = make_shared<AssignExpression>(yylhs.location,yystack_[2].value.as < shared_ptr<Id> > (),yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2506 "src/syntactic_parser.cpp"
    break;

  case 95: // assign_expressions: assign_expression
#line 624 "src/syntactic_parser.yy"
                     {
        yylhs.value.as < shared_ptr<AssignExpressions> > () = make_shared<AssignExpressions>(yylhs.location);
        if(yylhs.value.as < shared_ptr<AssignExpressions> > ()){
            yylhs.value.as < shared_ptr<AssignExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<AssignExpression> > ());
        }
    }
#line 2517 "src/syntactic_parser.cpp"
    break;

  case 96: // assign_expressions: assign_expressions ";" assign_expression
#line 630 "src/syntactic_parser.yy"
                                                  {
        yylhs.value.as < shared_ptr<AssignExpressions> > () = yystack_[2].value.as < shared_ptr<AssignExpressions> > ();
        if (yylhs.value.as < shared_ptr<AssignExpressions> > ()) {
            yylhs.value.as < shared_ptr<AssignExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<AssignExpression> > ());
        }
    }
#line 2528 "src/syntactic_parser.cpp"
    break;

  case 97: // array_expression: expression
#line 639 "src/syntactic_parser.yy"
                  {
        yylhs.value.as < shared_ptr<ArrayExpression> > () = make_shared<ArrayExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<Expression> > ());
    }
#line 2536 "src/syntactic_parser.cpp"
    break;

  case 98: // array_expression: expression OF expression
#line 642 "src/syntactic_parser.yy"
                                   {
        yylhs.value.as < shared_ptr<ArrayExpression> > () = make_shared<ArrayExpression>(yylhs.location,yystack_[0].value.as < shared_ptr<Expression> > (),yystack_[2].value.as < shared_ptr<Expression> > ());
    }
#line 2544 "src/syntactic_parser.cpp"
    break;

  case 99: // array_expressions: array_expression
#line 648 "src/syntactic_parser.yy"
                    {
        yylhs.value.as < shared_ptr<ArrayExpressions> > () = make_shared<ArrayExpressions>(yylhs.location);
        if(yylhs.value.as < shared_ptr<ArrayExpressions> > ()){
            yylhs.value.as < shared_ptr<ArrayExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<ArrayExpression> > ());
        }
    }
#line 2555 "src/syntactic_parser.cpp"
    break;

  case 100: // array_expressions: array_expressions "," array_expression
#line 654 "src/syntactic_parser.yy"
                                            {
        yylhs.value.as < shared_ptr<ArrayExpressions> > () = yystack_[2].value.as < shared_ptr<ArrayExpressions> > ();
        if(yylhs.value.as < shared_ptr<ArrayExpressions> > ()){
            yylhs.value.as < shared_ptr<ArrayExpressions> > ()->Insert(yystack_[0].value.as < shared_ptr<ArrayExpression> > ());
        }
    }
#line 2566 "src/syntactic_parser.cpp"
    break;

  case 101: // number: integer
#line 663 "src/syntactic_parser.yy"
            {
        yylhs.value.as < shared_ptr<Number> > () = make_shared<Number>(yylhs.location,yystack_[0].value.as < shared_ptr<INTEGER> > ());
    }
#line 2574 "src/syntactic_parser.cpp"
    break;

  case 102: // number: real
#line 666 "src/syntactic_parser.yy"
        {
        yylhs.value.as < shared_ptr<Number> > () = make_share<Number>(yylhs.location,yystack_[0].value.as < shared_ptr<REAL> > ());
    }
#line 2582 "src/syntactic_parser.cpp"
    break;

  case 103: // integer: "integer"
#line 672 "src/syntactic_parser.yy"
            {
        yylhs.value.as < shared_ptr<INTEGER> > () = make_shared<Integer>(yylhs.location, yystack_[0].value.as < std::string > ())
    }
#line 2590 "src/syntactic_parser.cpp"
    break;

  case 104: // real: "real"
#line 678 "src/syntactic_parser.yy"
         {
        yylhs.value.as < shared_ptr<REAL> > () = make_shared<Real>(yylhs.location, yystack_[0].value.as < std::string > ())
    }
#line 2598 "src/syntactic_parser.cpp"
    break;

  case 105: // string: "string"
#line 684 "src/syntactic_parser.yy"
           {
        yylhs.value.as < shared_ptr<STRING> > () = make_shared<String>(yylhs.location, yystack_[0].value.as < std::string > ())
    }
#line 2606 "src/syntactic_parser.cpp"
    break;

  case 106: // lvalues: lvalue
#line 690 "src/syntactic_parser.yy"
          {
        yylhs.value.as < shared_ptr<Lvalues> > () = make_shared<Lvalues>(yylhs.location);
        if(yylhs.value.as < shared_ptr<Lvalues> > ()){
            yylhs.value.as < shared_ptr<Lvalues> > ()->Insert(yystack_[0].value.as < shared_ptr<Lvalue> > ());
        }
    }
#line 2617 "src/syntactic_parser.cpp"
    break;

  case 107: // lvalues: lvalues "," lvalue
#line 696 "src/syntactic_parser.yy"
                        {
        yylhs.value.as < shared_ptr<Lvalues> > () = yystack_[2].value.as < shared_ptr<Lvalues> > ();
        if(yylhs.value.as < shared_ptr<Lvalues> > ()){
            yylhs.value.as < shared_ptr<Lvalues> > ()->Insert(yystack_[0].value.as < shared_ptr<Lvalue> > ());
        }
    }
#line 2628 "src/syntactic_parser.cpp"
    break;

  case 108: // lvalue: id
#line 705 "src/syntactic_parser.yy"
      {
        yylhs.value.as < shared_ptr<Lvalue> > () = make_shared<IdLvalue>(yylhs.location,yystack_[0].value.as < shared_ptr<Id> > ());
    }
#line 2636 "src/syntactic_parser.cpp"
    break;

  case 109: // lvalue: lvalue "[" expression "]"
#line 708 "src/syntactic_parser.yy"
                                   {
        yylhs.value.as < shared_ptr<Lvalue> > () = make_shared<ArrayElementvalue>(yylhs.location,yystack_[3].value.as < shared_ptr<Lvalue> > (),yystack_[1].value.as < shared_ptr<Expression> > ());
    }
#line 2644 "src/syntactic_parser.cpp"
    break;

  case 110: // lvalue: lvalue "." id
#line 711 "src/syntactic_parser.yy"
                 {
        yylhs.value.as < shared_ptr<Lvalue> > () = make_shared<RecordComponentLvalue>(yylhs.location,yystack_[2].value.as < shared_ptr<Lvalue> > (),yystack_[0].value.as < shared_ptr<Id> > ());
    }
#line 2652 "src/syntactic_parser.cpp"
    break;

  case 111: // component_values: assign_expressions
#line 717 "src/syntactic_parser.yy"
                       {
        yylhs.value.as < shared_ptr<ComponentValues> > () = make_shared<ComponentValues>(yylhs.location,yystack_[0].value.as < shared_ptr<AssignExpressions> > ());
    }
#line 2660 "src/syntactic_parser.cpp"
    break;

  case 112: // array_values: array_expressions
#line 723 "src/syntactic_parser.yy"
                      {
        yylhs.value.as < shared_ptr<ArrayValues> > () = make_shared<ArrayValues>(yylhs.location,yystack_[0].value.as < shared_ptr<ArrayExpressions> > ());
    }
#line 2668 "src/syntactic_parser.cpp"
    break;


#line 2672 "src/syntactic_parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  Parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  Parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  Parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -40;

  const signed char Parser::yytable_ninf_ = -63;

  const short
  Parser::yypact_[] =
  {
      14,    30,    29,    60,   -39,    31,   -40,   -40,   -40,   -40,
      18,    17,    19,   -40,    25,   209,   -40,   -40,    18,    38,
      53,   -40,    16,    91,    61,   -40,   104,   -40,   -25,   -40,
      62,   -40,    64,    18,   282,   -40,    68,   234,   282,    71,
      74,   -40,     1,   -40,    18,   -40,   -40,     7,   -40,   -40,
      18,     7,   103,   -40,   -40,   108,   282,   282,   282,   282,
     -40,   -40,    63,   476,   -40,   -40,   -40,    -5,   232,    18,
     -40,   326,   518,   105,   282,   282,   282,    18,   -40,    27,
      12,   118,    21,    72,   -40,   -40,   -40,   282,   282,   -40,
     -40,   -40,   449,   282,    18,   282,   282,   282,   282,   282,
     -40,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,    86,   -40,   101,    97,    -5,   -40,   -40,   -40,   107,
     653,   -40,    98,   -40,   109,   653,   117,   353,   407,   -40,
     102,    18,     7,     7,   116,   -40,     8,   120,   -40,   380,
     545,   -40,   114,   136,   -40,   121,   125,   572,   -40,   132,
     115,   422,   -40,   -40,   669,   119,     6,     6,   -40,   -40,
     492,   492,   492,   492,   696,   696,   -40,   123,    18,   249,
     133,   105,   134,   282,   -40,   -40,     9,   -40,   -40,   -40,
     -40,   -40,   -40,     7,   -40,   282,   -40,   282,    18,   -40,
     282,   282,   -40,    76,   -40,    -5,   135,   -40,   -40,   -40,
     653,   -40,   -40,   148,   599,   653,   -40,   653,   -40,   -40,
     282,   -40,   178,   -40,   149,   150,   -40,   282,   197,   272,
     626,   159,   -40,   -40,   653,   -40,   -40,   -40,   299,   181,
     162,   -40
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     9,     0,     0,     0,     0,     9,     1,     3,    51,
       0,     0,     0,    10,     0,     0,    36,    21,     7,     0,
       0,    17,     0,     0,     0,    13,     0,    37,    31,     2,
       0,     5,     0,     0,     0,    51,     0,     0,     0,     0,
     108,    52,     0,    22,    24,    16,    18,     0,    12,    14,
       0,     0,     0,    50,    49,     0,     0,     0,     0,     0,
     103,   104,   108,     0,    66,   101,   102,    65,     0,     0,
      48,     0,     0,    57,    53,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    27,    38,    30,     0,     0,    70,
      68,    69,     0,    53,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,    55,   106,    47,    51,   105,     0,
      90,    92,    56,    91,     0,    88,    54,     0,     0,   110,
      31,     0,     0,     0,     0,    34,     0,     0,    15,     0,
       0,    67,     0,     0,    95,   111,     0,    97,    99,   112,
       0,    77,    74,    76,    78,     0,    71,    72,    73,    75,
      81,    82,    83,    84,    79,    80,    45,     0,     0,     0,
       0,     0,     0,     0,    39,   109,     0,    26,    23,    28,
      33,    29,    35,     0,    11,     0,    85,     0,     0,    86,
       0,     0,    87,    61,    42,   107,     0,    43,    93,    40,
      89,     9,     9,     0,    63,    94,    96,    98,   100,    51,
       0,    60,     0,    44,     0,     0,    32,     0,     0,     0,
       0,     0,    20,    19,    64,    51,    51,    41,     0,     0,
       0,    46
  };

  const short
  Parser::yypgoto_[] =
  {
     -40,   -40,    -2,   -40,   -40,   198,   -40,   203,   -40,   210,
     -40,    96,   -40,   -22,    99,    94,   -40,   -10,   -37,   -40,
     -29,   138,   -40,   -40,   -40,   -40,   -40,   -40,    -6,   -40,
      66,   -40,    44,   -40,    47,   -40,   -40,   -40,   -40,   -40,
     -40,   -12,   -40,   -40
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     3,     4,    13,     5,    25,    26,    21,    22,    17,
      18,    78,    79,    83,    52,   135,   136,    62,    28,    41,
      15,   124,   113,   119,   211,   193,   212,   218,   120,   126,
     121,   122,   144,   145,   148,   149,    64,    65,    66,   123,
     114,    67,   146,   150
  };

  const short
  Parser::yytable_[] =
  {
      19,    23,    27,    42,    14,    40,    68,    80,    19,   134,
     201,    81,    23,    97,     8,     1,    27,    20,    20,   181,
      24,    -8,   134,    55,    98,   202,    50,    51,    63,    86,
      -4,    71,    72,    82,    27,    75,     9,    84,     2,    -8,
      85,    84,    76,   103,   104,     6,    -8,    -8,    76,    77,
      89,    90,    91,    92,    10,    77,    42,   115,    40,   112,
       7,    11,    12,    50,   132,    16,    16,   129,   125,   127,
     128,   155,   137,   130,    16,    16,    16,    16,    29,    16,
     131,   139,   140,    44,   143,   209,   210,   125,   169,   147,
     151,   152,   153,   154,    80,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    24,    45,    47,    93,    -6,
     178,   179,    94,    69,    48,    53,    73,    54,    95,    74,
      30,    27,    84,    84,    56,   138,   137,    -6,   -59,   -59,
     -59,    32,    33,    34,    -6,    -6,    35,    87,   133,   166,
      57,    58,    88,    42,    36,    40,    37,   167,   168,   171,
      59,    38,    39,   170,    51,   172,   195,    42,   112,    40,
     186,   203,    16,    16,    60,    61,   118,   200,   173,   180,
     187,   192,   183,    84,   188,   189,   194,    16,   143,   204,
     219,   205,    30,   191,   207,   147,   197,   199,   213,   221,
     -58,   -58,   -58,    32,    33,    34,   228,   229,    35,   214,
     215,   216,   222,   223,   220,   225,    36,    42,    37,    40,
      30,   224,   227,    38,    39,   231,    42,    42,    40,    40,
      31,    32,    33,    34,    49,    46,    35,   177,    43,   176,
     182,   142,   206,    30,    36,     0,    37,   198,   208,    16,
       0,    38,    39,   111,    32,    33,    34,     0,     0,    35,
      30,     0,     0,    56,     0,     0,     0,    36,     0,    37,
     196,    32,    33,    34,    38,    39,    35,    16,     0,    57,
      58,     0,     0,    30,    36,     0,    37,     0,     0,    59,
       0,    38,    39,   -62,    32,    33,    34,    70,     0,    35,
      16,     0,    16,    60,    61,     0,     0,    36,     0,    37,
      30,    56,     0,     0,    38,    39,     0,    16,     0,     0,
     230,    32,    33,    34,     0,     0,    35,    57,    58,     0,
       0,     0,     0,     0,    36,     0,    37,    59,     0,    96,
      16,    38,    39,    97,     0,     0,     0,     0,     0,     0,
      16,    60,    61,     0,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,    96,    16,     0,     0,
      97,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    98,     0,     0,    99,     0,     0,     0,     0,   116,
       0,     0,     0,    96,     0,     0,     0,    97,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    98,     0,
       0,    99,     0,     0,     0,     0,   174,     0,     0,     0,
      96,     0,     0,     0,    97,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    98,     0,     0,    99,    97,
       0,     0,     0,   184,     0,     0,     0,     0,     0,     0,
      98,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    96,     0,     0,   175,    97,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,     0,    97,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    98,   141,     0,    99,     0,    97,
       0,     0,     0,     0,   100,     0,     0,     0,     0,     0,
      98,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    96,     0,     0,     0,    97,   117,   101,   102,   103,
     104,   -63,   -63,   -63,   -63,     0,    98,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,    97,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    98,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   185,    96,     0,     0,     0,    97,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      98,     0,   190,    99,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,   217,    97,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,    98,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,     0,    97,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    98,     0,     0,    99,     0,     0,
       0,     0,     0,     0,   226,     0,    96,     0,     0,     0,
      97,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    98,    96,     0,    99,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,    97,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   -63,
     -63
  };

  const short
  Parser::yycheck_[] =
  {
      10,    11,    12,    15,     6,    15,    35,    44,    18,     1,
       1,     4,    22,     7,    53,     1,    26,     1,     1,    11,
       1,     5,     1,    33,    18,    16,    51,    52,    34,    51,
       0,    37,    38,    26,    44,    34,     5,    47,    24,    23,
      50,    51,    47,    37,    38,    16,    30,    31,    47,    54,
      56,    57,    58,    59,    23,    54,    68,    69,    68,    69,
       0,    30,    31,    51,    52,    58,    58,    77,    74,    75,
      76,   100,    82,    46,    58,    58,    58,    58,    53,    58,
      53,    87,    88,    45,    94,     9,    10,    93,   117,    95,
      96,    97,    98,    99,   131,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     1,    53,    16,    45,     5,
     132,   133,    49,    45,    53,    53,    45,    53,    55,    45,
       1,   131,   132,   133,    19,    53,   136,    23,     9,    10,
      11,    12,    13,    14,    30,    31,    17,    34,    20,    53,
      35,    36,    34,   155,    25,   155,    27,    46,    51,    51,
      45,    32,    33,    46,    52,    46,   168,   169,   168,   169,
      46,   183,    58,    58,    59,    60,    61,   173,    51,    53,
      34,    56,    52,   183,    53,    50,    53,    58,   188,   185,
     209,   187,     1,    51,   190,   191,    53,    53,    53,    11,
       9,    10,    11,    12,    13,    14,   225,   226,    17,   201,
     202,    53,    53,    53,   210,     8,    25,   219,    27,   219,
       1,   217,    53,    32,    33,    53,   228,   229,   228,   229,
      11,    12,    13,    14,    26,    22,    17,   131,    18,   130,
     136,    93,   188,     1,    25,    -1,    27,   171,   191,    58,
      -1,    32,    33,    11,    12,    13,    14,    -1,    -1,    17,
       1,    -1,    -1,    19,    -1,    -1,    -1,    25,    -1,    27,
      11,    12,    13,    14,    32,    33,    17,    58,    -1,    35,
      36,    -1,    -1,     1,    25,    -1,    27,    -1,    -1,    45,
      -1,    32,    33,    11,    12,    13,    14,    53,    -1,    17,
      58,    -1,    58,    59,    60,    -1,    -1,    25,    -1,    27,
       1,    19,    -1,    -1,    32,    33,    -1,    58,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,    17,    35,    36,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    45,    -1,     3,
      58,    32,    33,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    59,    60,    -1,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    58,    -1,    -1,
       7,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,     3,    -1,    -1,    -1,     7,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
       3,    -1,    -1,    -1,     7,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    18,    -1,    -1,    21,     7,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     3,    -1,    -1,    48,     7,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,     7,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    18,    46,    -1,    21,    -1,     7,
      -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,
      18,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     3,    -1,    -1,    -1,     7,     8,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    18,    -1,    -1,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,     7,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    18,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,     3,    -1,    -1,    -1,     7,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      18,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,     7,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    18,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,     3,    -1,    -1,    -1,
       7,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    18,     3,    -1,    21,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,     7,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     1,    24,    65,    66,    68,    16,     0,    53,     5,
      23,    30,    31,    67,    66,    84,    58,    73,    74,    81,
       1,    71,    72,    81,     1,    69,    70,    81,    82,    53,
       1,    11,    12,    13,    14,    17,    25,    27,    32,    33,
      81,    83,   105,    73,    45,    53,    71,    16,    53,    69,
      51,    52,    78,    53,    53,    81,    19,    35,    36,    45,
      59,    60,    81,    92,   100,   101,   102,   105,    84,    45,
      53,    92,    92,    45,    45,    34,    47,    54,    75,    76,
      82,     4,    26,    77,    81,    81,    77,    34,    34,    92,
      92,    92,    92,    45,    49,    55,     3,     7,    18,    21,
      28,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    11,    81,    86,   104,   105,    53,     8,    61,    87,
      92,    94,    95,   103,    85,    92,    93,    92,    92,    81,
      46,    53,    52,    20,     1,    79,    80,    81,    53,    92,
      92,    46,    85,    81,    96,    97,   106,    92,    98,    99,
     107,    92,    92,    92,    92,    84,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    53,    46,    51,    84,
      46,    51,    46,    51,    53,    48,    78,    75,    77,    77,
      53,    11,    79,    52,    53,    29,    46,    34,    53,    50,
      20,    51,    56,    89,    53,   105,    11,    53,    94,    53,
      92,     1,    16,    77,    92,    92,    96,    92,    98,     9,
      10,    88,    90,    53,    66,    66,    53,     6,    91,    84,
      92,    11,    53,    53,    92,     8,    28,    53,    84,    84,
      11,    53
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    64,    65,    65,    65,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    76,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    85,    85,    86,    87,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   102,   103,   104,   104,   105,   105,
     105,   106,   107
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     4,     3,     1,     4,     2,     2,     2,     0,
       2,     5,     2,     1,     2,     4,     2,     1,     2,     8,
       8,     1,     2,     3,     0,     1,     3,     1,     3,     3,
       2,     0,     4,     2,     1,     2,     1,     1,     3,     4,
       5,     8,     5,     5,     6,     4,    11,     3,     2,     2,
       2,     0,     2,     0,     1,     1,     1,     0,     4,     0,
       2,     0,     2,     0,     2,     1,     1,     3,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     1,     3,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ARRAY",
  "BEGIN", "BY", "DIV", "DO", "ELSE", "ELSIF", "END", "EXIT", "FOR", "IF",
  "IN", "IS", "LOOP", "MOD", "NOT", "OF", "OR", "OUT", "PROCEDURE",
  "PROGRAM", "READ", "RECORD", "RETURN", "THEN", "TO", "TYPE", "VAR",
  "WHILE", "WRITE", "\":=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"<\"",
  "\"<=\"", "\">\"", "\">=\"", "\"=\"", "\"<>\"", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\"{\"", "\"}\"", "\",\"", "\":\"", "\";\"", "\".\"",
  "\"[<\"", "\">]\"", "\"\\\\\"", "\"identifier\"", "\"integer\"",
  "\"real\"", "\"string\"", "POS", "NEG", "$accept", "program", "body",
  "declaration", "declarations", "variable_declaration",
  "variable_declarations", "type_declaration", "type_declarations",
  "procedure_declaration", "procedure_declarations", "formal_parameter",
  "formal_parameters", "type", "type_annotation", "component",
  "components", "id", "ids", "statement", "statements",
  "actual_parameters", "read_parameters", "write_parameters",
  "elif_section", "elif_sections", "else_section", "for_step",
  "expression", "expressions", "write_expression", "write_expressions",
  "assign_expression", "assign_expressions", "array_expression",
  "array_expressions", "number", "integer", "real", "string", "lvalues",
  "lvalue", "component_values", "array_values", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   192,   192,   196,   201,   205,   212,   216,   220,   227,
     230,   237,   240,   247,   251,   258,   261,   265,   271,   280,
     283,   290,   297,   306,   312,   315,   321,   330,   333,   336,
     342,   345,   351,   354,   359,   362,   368,   374,   377,   386,
     389,   392,   395,   398,   401,   404,   407,   410,   413,   417,
     420,   427,   430,   436,   439,   448,   457,   463,   469,   475,
     478,   487,   490,   496,   499,   507,   510,   513,   516,   519,
     522,   525,   528,   531,   534,   537,   540,   543,   546,   549,
     552,   555,   558,   561,   564,   567,   570,   573,   579,   585,
     594,   597,   603,   609,   618,   624,   630,   639,   642,   648,
     654,   663,   666,   672,   678,   684,   690,   696,   705,   708,
     711,   717,   723
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 3544 "src/syntactic_parser.cpp"

#line 727 "src/syntactic_parser.yy"


void yy::Parser::error(const location_type& l, const std::string& m) {
    Logger::Error(m,&l);
    Logger::Error(m,&l,p_driver->ofs());
}


