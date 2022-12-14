// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file src/syntactic_parser.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_SRC_SYNTACTIC_PARSER_H_INCLUDED
# define YY_YY_SRC_SYNTACTIC_PARSER_H_INCLUDED
// "%code requires" blocks.
#line 21 "src/syntactic_parser.yy"

    #include <string>

    #include "ast/ast.h"
    #include "base/common.h"

    class Driver;
    namespace yy {
        class Lexer;
    }

#line 61 "src/syntactic_parser.h"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.h"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 201 "src/syntactic_parser.h"




  /// A Bison parser.
  class Parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // actual_parameters
      char dummy1[sizeof (shared_ptr<ActualParameters>)];

      // array_expression
      char dummy2[sizeof (shared_ptr<ArrayExpression>)];

      // array_expressions
      char dummy3[sizeof (shared_ptr<ArrayExpressions>)];

      // array_values
      char dummy4[sizeof (shared_ptr<ArrayValues>)];

      // assign_expression
      char dummy5[sizeof (shared_ptr<AssignExpression>)];

      // assign_expressions
      char dummy6[sizeof (shared_ptr<AssignExpressions>)];

      // body
      char dummy7[sizeof (shared_ptr<Body>)];

      // component
      char dummy8[sizeof (shared_ptr<Component>)];

      // component_values
      char dummy9[sizeof (shared_ptr<ComponentValues>)];

      // components
      char dummy10[sizeof (shared_ptr<Components>)];

      // declaration
      // declarations
      char dummy11[sizeof (shared_ptr<Declaration>)];

      // elif_section
      char dummy12[sizeof (shared_ptr<ElifSection>)];

      // elif_sections
      char dummy13[sizeof (shared_ptr<ElifSections>)];

      // else_section
      char dummy14[sizeof (shared_ptr<ElseSection>)];

      // expression
      char dummy15[sizeof (shared_ptr<Expression>)];

      // expressions
      char dummy16[sizeof (shared_ptr<Expressions>)];

      // for_step
      char dummy17[sizeof (shared_ptr<ForStep>)];

      // formal_parameter
      char dummy18[sizeof (shared_ptr<FormalParameter>)];

      // formal_parameters
      char dummy19[sizeof (shared_ptr<FormalParameters>)];

      // integer
      char dummy20[sizeof (shared_ptr<INTEGER>)];

      // id
      char dummy21[sizeof (shared_ptr<Id>)];

      // ids
      char dummy22[sizeof (shared_ptr<Ids>)];

      // lvalue
      char dummy23[sizeof (shared_ptr<Lvalue>)];

      // lvalues
      char dummy24[sizeof (shared_ptr<Lvalues>)];

      // number
      char dummy25[sizeof (shared_ptr<Number>)];

      // procedure_declaration
      char dummy26[sizeof (shared_ptr<ProcedureDeclaration>)];

      // procedure_declarations
      char dummy27[sizeof (shared_ptr<ProcedureDeclarations>)];

      // program
      char dummy28[sizeof (shared_ptr<Program>)];

      // real
      char dummy29[sizeof (shared_ptr<REAL>)];

      // read_parameters
      char dummy30[sizeof (shared_ptr<ReadParameters>)];

      // string
      char dummy31[sizeof (shared_ptr<STRING>)];

      // statement
      char dummy32[sizeof (shared_ptr<Statement>)];

      // statements
      char dummy33[sizeof (shared_ptr<Statements>)];

      // type
      char dummy34[sizeof (shared_ptr<Type>)];

      // type_annotation
      char dummy35[sizeof (shared_ptr<TypeAnnotation>)];

      // type_declaration
      char dummy36[sizeof (shared_ptr<TypeDeclaration>)];

      // type_declarations
      char dummy37[sizeof (shared_ptr<TypeDeclarations>)];

      // variable_declaration
      char dummy38[sizeof (shared_ptr<VariableDeclaration>)];

      // variable_declarations
      char dummy39[sizeof (shared_ptr<VariableDeclarations>)];

      // write_expression
      char dummy40[sizeof (shared_ptr<WriteExpression>)];

      // write_expressions
      char dummy41[sizeof (shared_ptr<WriteExpressions>)];

      // write_parameters
      char dummy42[sizeof (shared_ptr<WriteParameters>)];

      // AND
      // ARRAY
      // BEGIN
      // BY
      // DIV
      // DO
      // ELSE
      // ELSIF
      // END
      // EXIT
      // FOR
      // IF
      // IN
      // IS
      // LOOP
      // MOD
      // NOT
      // OF
      // OR
      // OUT
      // PROCEDURE
      // PROGRAM
      // READ
      // RECORD
      // RETURN
      // THEN
      // TO
      // TYPE
      // VAR
      // WHILE
      // WRITE
      // ":="
      // "+"
      // "-"
      // "*"
      // "/"
      // "<"
      // "<="
      // ">"
      // ">="
      // "="
      // "<>"
      // "("
      // ")"
      // "["
      // "]"
      // "{"
      // "}"
      // ","
      // ":"
      // ";"
      // "."
      // "[<"
      // ">]"
      // "\\"
      // "identifier"
      // "integer"
      // "real"
      // "string"
      char dummy43[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        T_YYEMPTY = -2,
    T_YYEOF = 0,                   // "end of file"
    T_YYerror = 1,                 // error
    T_YYUNDEF = 2,                 // "invalid token"
    T_AND = 3,                     // AND
    T_ARRAY = 4,                   // ARRAY
    T_BEGIN = 5,                   // BEGIN
    T_BY = 6,                      // BY
    T_DIV = 7,                     // DIV
    T_DO = 8,                      // DO
    T_ELSE = 9,                    // ELSE
    T_ELSIF = 10,                  // ELSIF
    T_END = 11,                    // END
    T_EXIT = 12,                   // EXIT
    T_FOR = 13,                    // FOR
    T_IF = 14,                     // IF
    T_IN = 15,                     // IN
    T_IS = 16,                     // IS
    T_LOOP = 17,                   // LOOP
    T_MOD = 18,                    // MOD
    T_NOT = 19,                    // NOT
    T_OF = 20,                     // OF
    T_OR = 21,                     // OR
    T_OUT = 22,                    // OUT
    T_PROCEDURE = 23,              // PROCEDURE
    T_PROGRAM = 24,                // PROGRAM
    T_READ = 25,                   // READ
    T_RECORD = 26,                 // RECORD
    T_RETURN = 27,                 // RETURN
    T_THEN = 28,                   // THEN
    T_TO = 29,                     // TO
    T_TYPE = 30,                   // TYPE
    T_VAR = 31,                    // VAR
    T_WHILE = 32,                  // WHILE
    T_WRITE = 33,                  // WRITE
    T_ASSIGN = 34,                 // ":="
    T_PLUS = 35,                   // "+"
    T_MINUS = 36,                  // "-"
    T_MULT = 37,                   // "*"
    T_DIVIDE = 38,                 // "/"
    T_LT = 39,                     // "<"
    T_LE = 40,                     // "<="
    T_GT = 41,                     // ">"
    T_GE = 42,                     // ">="
    T_EQ = 43,                     // "="
    T_NE = 44,                     // "<>"
    T_LPAREN = 45,                 // "("
    T_RPAREN = 46,                 // ")"
    T_LBRACK = 47,                 // "["
    T_RBRACK = 48,                 // "]"
    T_LBRACE = 49,                 // "{"
    T_RBRACE = 50,                 // "}"
    T_COMMA = 51,                  // ","
    T_COLON = 52,                  // ":"
    T_SEMICOLON = 53,              // ";"
    T_DOT = 54,                    // "."
    T_LSABRAC = 55,                // "[<"
    T_RSABRAC = 56,                // ">]"
    T_BACKSLASH = 57,              // "\\"
    T_ID = 58,                     // "identifier"
    T_INTEGER = 59,                // "integer"
    T_REAL = 60,                   // "real"
    T_STRING = 61,                 // "string"
    T_POS = 62,                    // POS
    T_NEG = 63                     // NEG
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 64, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_AND = 3,                               // AND
        S_ARRAY = 4,                             // ARRAY
        S_BEGIN = 5,                             // BEGIN
        S_BY = 6,                                // BY
        S_DIV = 7,                               // DIV
        S_DO = 8,                                // DO
        S_ELSE = 9,                              // ELSE
        S_ELSIF = 10,                            // ELSIF
        S_END = 11,                              // END
        S_EXIT = 12,                             // EXIT
        S_FOR = 13,                              // FOR
        S_IF = 14,                               // IF
        S_IN = 15,                               // IN
        S_IS = 16,                               // IS
        S_LOOP = 17,                             // LOOP
        S_MOD = 18,                              // MOD
        S_NOT = 19,                              // NOT
        S_OF = 20,                               // OF
        S_OR = 21,                               // OR
        S_OUT = 22,                              // OUT
        S_PROCEDURE = 23,                        // PROCEDURE
        S_PROGRAM = 24,                          // PROGRAM
        S_READ = 25,                             // READ
        S_RECORD = 26,                           // RECORD
        S_RETURN = 27,                           // RETURN
        S_THEN = 28,                             // THEN
        S_TO = 29,                               // TO
        S_TYPE = 30,                             // TYPE
        S_VAR = 31,                              // VAR
        S_WHILE = 32,                            // WHILE
        S_WRITE = 33,                            // WRITE
        S_ASSIGN = 34,                           // ":="
        S_PLUS = 35,                             // "+"
        S_MINUS = 36,                            // "-"
        S_MULT = 37,                             // "*"
        S_DIVIDE = 38,                           // "/"
        S_LT = 39,                               // "<"
        S_LE = 40,                               // "<="
        S_GT = 41,                               // ">"
        S_GE = 42,                               // ">="
        S_EQ = 43,                               // "="
        S_NE = 44,                               // "<>"
        S_LPAREN = 45,                           // "("
        S_RPAREN = 46,                           // ")"
        S_LBRACK = 47,                           // "["
        S_RBRACK = 48,                           // "]"
        S_LBRACE = 49,                           // "{"
        S_RBRACE = 50,                           // "}"
        S_COMMA = 51,                            // ","
        S_COLON = 52,                            // ":"
        S_SEMICOLON = 53,                        // ";"
        S_DOT = 54,                              // "."
        S_LSABRAC = 55,                          // "[<"
        S_RSABRAC = 56,                          // ">]"
        S_BACKSLASH = 57,                        // "\\"
        S_ID = 58,                               // "identifier"
        S_INTEGER = 59,                          // "integer"
        S_REAL = 60,                             // "real"
        S_STRING = 61,                           // "string"
        S_POS = 62,                              // POS
        S_NEG = 63,                              // NEG
        S_YYACCEPT = 64,                         // $accept
        S_program = 65,                          // program
        S_body = 66,                             // body
        S_declaration = 67,                      // declaration
        S_declarations = 68,                     // declarations
        S_variable_declaration = 69,             // variable_declaration
        S_variable_declarations = 70,            // variable_declarations
        S_type_declaration = 71,                 // type_declaration
        S_type_declarations = 72,                // type_declarations
        S_procedure_declaration = 73,            // procedure_declaration
        S_procedure_declarations = 74,           // procedure_declarations
        S_formal_parameter = 75,                 // formal_parameter
        S_formal_parameters = 76,                // formal_parameters
        S_type = 77,                             // type
        S_type_annotation = 78,                  // type_annotation
        S_component = 79,                        // component
        S_components = 80,                       // components
        S_id = 81,                               // id
        S_ids = 82,                              // ids
        S_statement = 83,                        // statement
        S_statements = 84,                       // statements
        S_actual_parameters = 85,                // actual_parameters
        S_read_parameters = 86,                  // read_parameters
        S_write_parameters = 87,                 // write_parameters
        S_elif_section = 88,                     // elif_section
        S_elif_sections = 89,                    // elif_sections
        S_else_section = 90,                     // else_section
        S_for_step = 91,                         // for_step
        S_expression = 92,                       // expression
        S_expressions = 93,                      // expressions
        S_write_expression = 94,                 // write_expression
        S_write_expressions = 95,                // write_expressions
        S_assign_expression = 96,                // assign_expression
        S_assign_expressions = 97,               // assign_expressions
        S_array_expression = 98,                 // array_expression
        S_array_expressions = 99,                // array_expressions
        S_number = 100,                          // number
        S_integer = 101,                         // integer
        S_real = 102,                            // real
        S_string = 103,                          // string
        S_lvalues = 104,                         // lvalues
        S_lvalue = 105,                          // lvalue
        S_component_values = 106,                // component_values
        S_array_values = 107                     // array_values
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.move< shared_ptr<ActualParameters> > (std::move (that.value));
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.move< shared_ptr<ArrayExpression> > (std::move (that.value));
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.move< shared_ptr<ArrayExpressions> > (std::move (that.value));
        break;

      case symbol_kind::S_array_values: // array_values
        value.move< shared_ptr<ArrayValues> > (std::move (that.value));
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.move< shared_ptr<AssignExpression> > (std::move (that.value));
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.move< shared_ptr<AssignExpressions> > (std::move (that.value));
        break;

      case symbol_kind::S_body: // body
        value.move< shared_ptr<Body> > (std::move (that.value));
        break;

      case symbol_kind::S_component: // component
        value.move< shared_ptr<Component> > (std::move (that.value));
        break;

      case symbol_kind::S_component_values: // component_values
        value.move< shared_ptr<ComponentValues> > (std::move (that.value));
        break;

      case symbol_kind::S_components: // components
        value.move< shared_ptr<Components> > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.move< shared_ptr<Declaration> > (std::move (that.value));
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.move< shared_ptr<ElifSection> > (std::move (that.value));
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.move< shared_ptr<ElifSections> > (std::move (that.value));
        break;

      case symbol_kind::S_else_section: // else_section
        value.move< shared_ptr<ElseSection> > (std::move (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< shared_ptr<Expression> > (std::move (that.value));
        break;

      case symbol_kind::S_expressions: // expressions
        value.move< shared_ptr<Expressions> > (std::move (that.value));
        break;

      case symbol_kind::S_for_step: // for_step
        value.move< shared_ptr<ForStep> > (std::move (that.value));
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.move< shared_ptr<FormalParameter> > (std::move (that.value));
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.move< shared_ptr<FormalParameters> > (std::move (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< shared_ptr<INTEGER> > (std::move (that.value));
        break;

      case symbol_kind::S_id: // id
        value.move< shared_ptr<Id> > (std::move (that.value));
        break;

      case symbol_kind::S_ids: // ids
        value.move< shared_ptr<Ids> > (std::move (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< shared_ptr<Lvalue> > (std::move (that.value));
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.move< shared_ptr<Lvalues> > (std::move (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< shared_ptr<Number> > (std::move (that.value));
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.move< shared_ptr<ProcedureDeclaration> > (std::move (that.value));
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.move< shared_ptr<ProcedureDeclarations> > (std::move (that.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (std::move (that.value));
        break;

      case symbol_kind::S_real: // real
        value.move< shared_ptr<REAL> > (std::move (that.value));
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.move< shared_ptr<ReadParameters> > (std::move (that.value));
        break;

      case symbol_kind::S_string: // string
        value.move< shared_ptr<STRING> > (std::move (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (std::move (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< shared_ptr<Statements> > (std::move (that.value));
        break;

      case symbol_kind::S_type: // type
        value.move< shared_ptr<Type> > (std::move (that.value));
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.move< shared_ptr<TypeAnnotation> > (std::move (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< shared_ptr<TypeDeclaration> > (std::move (that.value));
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.move< shared_ptr<TypeDeclarations> > (std::move (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< shared_ptr<VariableDeclaration> > (std::move (that.value));
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.move< shared_ptr<VariableDeclarations> > (std::move (that.value));
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.move< shared_ptr<WriteExpression> > (std::move (that.value));
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.move< shared_ptr<WriteExpressions> > (std::move (that.value));
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.move< shared_ptr<WriteParameters> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ActualParameters>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ActualParameters>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ArrayExpression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ArrayExpression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ArrayExpressions>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ArrayExpressions>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ArrayValues>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ArrayValues>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<AssignExpression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<AssignExpression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<AssignExpressions>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<AssignExpressions>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Body>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Body>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Component>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Component>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ComponentValues>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ComponentValues>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Components>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Components>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Declaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Declaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ElifSection>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ElifSection>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ElifSections>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ElifSections>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ElseSection>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ElseSection>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Expression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Expression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Expressions>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Expressions>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ForStep>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ForStep>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<FormalParameter>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<FormalParameter>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<FormalParameters>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<FormalParameters>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<INTEGER>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<INTEGER>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Id>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Id>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Ids>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Ids>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Lvalue>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Lvalue>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Lvalues>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Lvalues>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Number>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Number>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ProcedureDeclaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ProcedureDeclaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ProcedureDeclarations>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ProcedureDeclarations>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Program>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Program>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<REAL>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<REAL>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<ReadParameters>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<ReadParameters>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<STRING>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<STRING>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Statement>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Statement>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Statements>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Statements>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<Type>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<Type>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<TypeAnnotation>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<TypeAnnotation>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<TypeDeclaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<TypeDeclaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<TypeDeclarations>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<TypeDeclarations>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<VariableDeclaration>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<VariableDeclaration>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<VariableDeclarations>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<VariableDeclarations>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<WriteExpression>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<WriteExpression>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<WriteExpressions>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<WriteExpressions>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, shared_ptr<WriteParameters>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const shared_ptr<WriteParameters>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.template destroy< shared_ptr<ActualParameters> > ();
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.template destroy< shared_ptr<ArrayExpression> > ();
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.template destroy< shared_ptr<ArrayExpressions> > ();
        break;

      case symbol_kind::S_array_values: // array_values
        value.template destroy< shared_ptr<ArrayValues> > ();
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.template destroy< shared_ptr<AssignExpression> > ();
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.template destroy< shared_ptr<AssignExpressions> > ();
        break;

      case symbol_kind::S_body: // body
        value.template destroy< shared_ptr<Body> > ();
        break;

      case symbol_kind::S_component: // component
        value.template destroy< shared_ptr<Component> > ();
        break;

      case symbol_kind::S_component_values: // component_values
        value.template destroy< shared_ptr<ComponentValues> > ();
        break;

      case symbol_kind::S_components: // components
        value.template destroy< shared_ptr<Components> > ();
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.template destroy< shared_ptr<Declaration> > ();
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.template destroy< shared_ptr<ElifSection> > ();
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.template destroy< shared_ptr<ElifSections> > ();
        break;

      case symbol_kind::S_else_section: // else_section
        value.template destroy< shared_ptr<ElseSection> > ();
        break;

      case symbol_kind::S_expression: // expression
        value.template destroy< shared_ptr<Expression> > ();
        break;

      case symbol_kind::S_expressions: // expressions
        value.template destroy< shared_ptr<Expressions> > ();
        break;

      case symbol_kind::S_for_step: // for_step
        value.template destroy< shared_ptr<ForStep> > ();
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.template destroy< shared_ptr<FormalParameter> > ();
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.template destroy< shared_ptr<FormalParameters> > ();
        break;

      case symbol_kind::S_integer: // integer
        value.template destroy< shared_ptr<INTEGER> > ();
        break;

      case symbol_kind::S_id: // id
        value.template destroy< shared_ptr<Id> > ();
        break;

      case symbol_kind::S_ids: // ids
        value.template destroy< shared_ptr<Ids> > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.template destroy< shared_ptr<Lvalue> > ();
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.template destroy< shared_ptr<Lvalues> > ();
        break;

      case symbol_kind::S_number: // number
        value.template destroy< shared_ptr<Number> > ();
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.template destroy< shared_ptr<ProcedureDeclaration> > ();
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.template destroy< shared_ptr<ProcedureDeclarations> > ();
        break;

      case symbol_kind::S_program: // program
        value.template destroy< shared_ptr<Program> > ();
        break;

      case symbol_kind::S_real: // real
        value.template destroy< shared_ptr<REAL> > ();
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.template destroy< shared_ptr<ReadParameters> > ();
        break;

      case symbol_kind::S_string: // string
        value.template destroy< shared_ptr<STRING> > ();
        break;

      case symbol_kind::S_statement: // statement
        value.template destroy< shared_ptr<Statement> > ();
        break;

      case symbol_kind::S_statements: // statements
        value.template destroy< shared_ptr<Statements> > ();
        break;

      case symbol_kind::S_type: // type
        value.template destroy< shared_ptr<Type> > ();
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.template destroy< shared_ptr<TypeAnnotation> > ();
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.template destroy< shared_ptr<TypeDeclaration> > ();
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.template destroy< shared_ptr<TypeDeclarations> > ();
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.template destroy< shared_ptr<VariableDeclaration> > ();
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.template destroy< shared_ptr<VariableDeclarations> > ();
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.template destroy< shared_ptr<WriteExpression> > ();
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.template destroy< shared_ptr<WriteExpressions> > ();
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.template destroy< shared_ptr<WriteParameters> > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::T_YYEOF
                   || (token::T_YYerror <= tok && tok <= token::T_YYUNDEF)
                   || (token::T_POS <= tok && tok <= token::T_NEG));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::T_AND <= tok && tok <= token::T_STRING));
#endif
      }
    };

    /// Build a parser object.
    Parser (yy::Lexer* p_lex_yyarg, Driver* p_driver_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::T_YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::T_YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::T_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::T_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::T_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::T_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::T_AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY (std::string v, location_type l)
      {
        return symbol_type (token::T_ARRAY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ARRAY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BEGIN (std::string v, location_type l)
      {
        return symbol_type (token::T_BEGIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BEGIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_BEGIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BY (std::string v, location_type l)
      {
        return symbol_type (token::T_BY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_BY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::T_DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO (std::string v, location_type l)
      {
        return symbol_type (token::T_DO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_DO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v, location_type l)
      {
        return symbol_type (token::T_ELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSIF (std::string v, location_type l)
      {
        return symbol_type (token::T_ELSIF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ELSIF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ELSIF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (std::string v, location_type l)
      {
        return symbol_type (token::T_END, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_END (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_END, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXIT (std::string v, location_type l)
      {
        return symbol_type (token::T_EXIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_EXIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (std::string v, location_type l)
      {
        return symbol_type (token::T_FOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_FOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v, location_type l)
      {
        return symbol_type (token::T_IF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_IF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN (std::string v, location_type l)
      {
        return symbol_type (token::T_IN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_IN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IS (std::string v, location_type l)
      {
        return symbol_type (token::T_IS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_IS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOOP (std::string v, location_type l)
      {
        return symbol_type (token::T_LOOP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOOP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LOOP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (std::string v, location_type l)
      {
        return symbol_type (token::T_MOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_MOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v, location_type l)
      {
        return symbol_type (token::T_NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OF (std::string v, location_type l)
      {
        return symbol_type (token::T_OF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_OF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::T_OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT (std::string v, location_type l)
      {
        return symbol_type (token::T_OUT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OUT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_OUT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROCEDURE (std::string v, location_type l)
      {
        return symbol_type (token::T_PROCEDURE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PROCEDURE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_PROCEDURE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROGRAM (std::string v, location_type l)
      {
        return symbol_type (token::T_PROGRAM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PROGRAM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_PROGRAM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READ (std::string v, location_type l)
      {
        return symbol_type (token::T_READ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_READ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_READ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECORD (std::string v, location_type l)
      {
        return symbol_type (token::T_RECORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RECORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RECORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v, location_type l)
      {
        return symbol_type (token::T_RETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (std::string v, location_type l)
      {
        return symbol_type (token::T_THEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_THEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TO (std::string v, location_type l)
      {
        return symbol_type (token::T_TO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_TO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::T_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (std::string v, location_type l)
      {
        return symbol_type (token::T_VAR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_VAR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v, location_type l)
      {
        return symbol_type (token::T_WHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_WHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WRITE (std::string v, location_type l)
      {
        return symbol_type (token::T_WRITE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WRITE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_WRITE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v, location_type l)
      {
        return symbol_type (token::T_ASSIGN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ASSIGN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS (std::string v, location_type l)
      {
        return symbol_type (token::T_PLUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PLUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_PLUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS (std::string v, location_type l)
      {
        return symbol_type (token::T_MINUS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MINUS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_MINUS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULT (std::string v, location_type l)
      {
        return symbol_type (token::T_MULT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MULT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_MULT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVIDE (std::string v, location_type l)
      {
        return symbol_type (token::T_DIVIDE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIVIDE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_DIVIDE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (std::string v, location_type l)
      {
        return symbol_type (token::T_LT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (std::string v, location_type l)
      {
        return symbol_type (token::T_LE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (std::string v, location_type l)
      {
        return symbol_type (token::T_GT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_GT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (std::string v, location_type l)
      {
        return symbol_type (token::T_GE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_GE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (std::string v, location_type l)
      {
        return symbol_type (token::T_EQ, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_EQ, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (std::string v, location_type l)
      {
        return symbol_type (token::T_NE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_NE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (std::string v, location_type l)
      {
        return symbol_type (token::T_LPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (std::string v, location_type l)
      {
        return symbol_type (token::T_RPAREN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RPAREN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACK (std::string v, location_type l)
      {
        return symbol_type (token::T_LBRACK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LBRACK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACK (std::string v, location_type l)
      {
        return symbol_type (token::T_RBRACK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RBRACK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (std::string v, location_type l)
      {
        return symbol_type (token::T_LBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (std::string v, location_type l)
      {
        return symbol_type (token::T_RBRACE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBRACE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RBRACE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v, location_type l)
      {
        return symbol_type (token::T_COMMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_COMMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (std::string v, location_type l)
      {
        return symbol_type (token::T_COLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_COLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (std::string v, location_type l)
      {
        return symbol_type (token::T_SEMICOLON, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_SEMICOLON, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v, location_type l)
      {
        return symbol_type (token::T_DOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_DOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LSABRAC (std::string v, location_type l)
      {
        return symbol_type (token::T_LSABRAC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LSABRAC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_LSABRAC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSABRAC (std::string v, location_type l)
      {
        return symbol_type (token::T_RSABRAC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSABRAC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_RSABRAC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BACKSLASH (std::string v, location_type l)
      {
        return symbol_type (token::T_BACKSLASH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BACKSLASH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_BACKSLASH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::T_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (std::string v, location_type l)
      {
        return symbol_type (token::T_INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REAL (std::string v, location_type l)
      {
        return symbol_type (token::T_REAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_REAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::T_STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::T_STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POS (location_type l)
      {
        return symbol_type (token::T_POS, std::move (l));
      }
#else
      static
      symbol_type
      make_POS (const location_type& l)
      {
        return symbol_type (token::T_POS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::T_NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::T_NEG, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif

    /// Check the lookahead yytoken.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_check_ (symbol_kind_type yytoken) const;
    /// Establish the initial context if no initial context currently exists.
    /// \returns  true iff the token will be eventually shifted.
    bool yy_lac_establish_ (symbol_kind_type yytoken);
    /// Discard any previous initial lookahead context because of event.
    /// \param event  the event which caused the lookahead to be discarded.
    ///               Only used for debbuging output.
    void yy_lac_discard_ (const char* event);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;
    /// The stack for LAC.
    /// Logically, the yy_lac_stack's lifetime is confined to the function
    /// yy_lac_check_. We just store it as a member of this class to hold
    /// on to the memory and to avoid frequent reallocations.
    /// Since yy_lac_check_ is const, this member must be mutable.
    mutable std::vector<state_type> yylac_stack_;
    /// Whether an initial LAC context was established.
    bool yy_lac_established_;


    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 740,     ///< Last index in yytable_.
      yynnts_ = 44,  ///< Number of nonterminal symbols.
      yyfinal_ = 7 ///< Termination state number.
    };


    // User arguments.
    yy::Lexer* p_lex;
    Driver* p_driver;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.copy< shared_ptr<ActualParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.copy< shared_ptr<ArrayExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.copy< shared_ptr<ArrayExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_values: // array_values
        value.copy< shared_ptr<ArrayValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.copy< shared_ptr<AssignExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.copy< shared_ptr<AssignExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_body: // body
        value.copy< shared_ptr<Body> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component: // component
        value.copy< shared_ptr<Component> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_component_values: // component_values
        value.copy< shared_ptr<ComponentValues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_components: // components
        value.copy< shared_ptr<Components> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.copy< shared_ptr<Declaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.copy< shared_ptr<ElifSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.copy< shared_ptr<ElifSections> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_else_section: // else_section
        value.copy< shared_ptr<ElseSection> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
        value.copy< shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expressions: // expressions
        value.copy< shared_ptr<Expressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_for_step: // for_step
        value.copy< shared_ptr<ForStep> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.copy< shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.copy< shared_ptr<FormalParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.copy< shared_ptr<INTEGER> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
        value.copy< shared_ptr<Id> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ids: // ids
        value.copy< shared_ptr<Ids> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< shared_ptr<Lvalue> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.copy< shared_ptr<Lvalues> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.copy< shared_ptr<Number> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.copy< shared_ptr<ProcedureDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.copy< shared_ptr<ProcedureDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
        value.copy< shared_ptr<Program> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_real: // real
        value.copy< shared_ptr<REAL> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.copy< shared_ptr<ReadParameters> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_string: // string
        value.copy< shared_ptr<STRING> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
        value.copy< shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.copy< shared_ptr<Statements> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type: // type
        value.copy< shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.copy< shared_ptr<TypeAnnotation> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.copy< shared_ptr<TypeDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.copy< shared_ptr<TypeDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.copy< shared_ptr<VariableDeclaration> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.copy< shared_ptr<VariableDeclarations> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.copy< shared_ptr<WriteExpression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.copy< shared_ptr<WriteExpressions> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.copy< shared_ptr<WriteParameters> > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_actual_parameters: // actual_parameters
        value.move< shared_ptr<ActualParameters> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_expression: // array_expression
        value.move< shared_ptr<ArrayExpression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_expressions: // array_expressions
        value.move< shared_ptr<ArrayExpressions> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_values: // array_values
        value.move< shared_ptr<ArrayValues> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assign_expression: // assign_expression
        value.move< shared_ptr<AssignExpression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assign_expressions: // assign_expressions
        value.move< shared_ptr<AssignExpressions> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_body: // body
        value.move< shared_ptr<Body> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_component: // component
        value.move< shared_ptr<Component> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_component_values: // component_values
        value.move< shared_ptr<ComponentValues> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_components: // components
        value.move< shared_ptr<Components> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarations: // declarations
        value.move< shared_ptr<Declaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_elif_section: // elif_section
        value.move< shared_ptr<ElifSection> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_elif_sections: // elif_sections
        value.move< shared_ptr<ElifSections> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_else_section: // else_section
        value.move< shared_ptr<ElseSection> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
        value.move< shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expressions: // expressions
        value.move< shared_ptr<Expressions> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_for_step: // for_step
        value.move< shared_ptr<ForStep> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formal_parameter: // formal_parameter
        value.move< shared_ptr<FormalParameter> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_formal_parameters: // formal_parameters
        value.move< shared_ptr<FormalParameters> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< shared_ptr<INTEGER> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id: // id
        value.move< shared_ptr<Id> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ids: // ids
        value.move< shared_ptr<Ids> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< shared_ptr<Lvalue> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lvalues: // lvalues
        value.move< shared_ptr<Lvalues> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_number: // number
        value.move< shared_ptr<Number> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_procedure_declaration: // procedure_declaration
        value.move< shared_ptr<ProcedureDeclaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_procedure_declarations: // procedure_declarations
        value.move< shared_ptr<ProcedureDeclarations> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_program: // program
        value.move< shared_ptr<Program> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_real: // real
        value.move< shared_ptr<REAL> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_read_parameters: // read_parameters
        value.move< shared_ptr<ReadParameters> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_string: // string
        value.move< shared_ptr<STRING> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statement: // statement
        value.move< shared_ptr<Statement> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< shared_ptr<Statements> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type: // type
        value.move< shared_ptr<Type> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_annotation: // type_annotation
        value.move< shared_ptr<TypeAnnotation> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_declaration: // type_declaration
        value.move< shared_ptr<TypeDeclaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_declarations: // type_declarations
        value.move< shared_ptr<TypeDeclarations> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_declaration: // variable_declaration
        value.move< shared_ptr<VariableDeclaration> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_variable_declarations: // variable_declarations
        value.move< shared_ptr<VariableDeclarations> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_write_expression: // write_expression
        value.move< shared_ptr<WriteExpression> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_write_expressions: // write_expressions
        value.move< shared_ptr<WriteExpressions> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_write_parameters: // write_parameters
        value.move< shared_ptr<WriteParameters> > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


} // yy
#line 4051 "src/syntactic_parser.h"




#endif // !YY_YY_SRC_SYNTACTIC_PARSER_H_INCLUDED
