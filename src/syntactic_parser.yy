%skeleton "lalr1.cc"// 使用 LALR1 语法分析器
%require "3.8"
%header "src/syntactic_parser.h"
%locations// 提供 location 接口，以便 Lexer 记录当前分析到的位置

%define api.location.file "location.h"
%define api.parser.class {Parser}
%define api.token.constructor // 提供 token 构造函数接口，以便 Lexer 返回 symbol_type 的 token
%define api.token.prefix {T_} // 为 token 名增加指定前缀
%define api.token.raw
%define api.value.type variant // 指定 token 语义值类型为 variant，用于同时支持更广泛的类型

%define parse.assert // 通过运行时检查确保 token 被正常构造与析构，以保证上述 variant 类型被正确使用
%define parse.trace
%define parse.error verbose
%define parse.lac full

%lex-param {yy::Lexer* p_lexer}
%parse-param {yy::Lexer* p_lexer} {Driver* p_driver}

%code requires {
    #include <string>

    #include "ast/ast.h"
    #include "base/common.h"

    class Driver;
    namespace yy {
        class Lexer;
    }
}

%code top {
    #include <memory> 

    #include "driver.h"
    #include "lexer.h"
    #include "utils/logger.h"

    using std::make_shared;
    using location_type = yy::Parser::location_type;
    using symbol_type = yy::Parser::symbol_type;

    static symbol_type yylex(yy::Lexer* p_lexer) {
        return p_lexer->ReadToken();
    }

    int yyFlexLexer::yylex() {
        Logger::Warn("Wrong yylex() called");
        return EXIT_FAILURE;
    }
}

%token
//reserved keywords
<std::string>   AND
<std::string>   ARRAY
<std::string>   BEGIN
<std::string>   BY
<std::string>   DIV
<std::string>   DO
<std::string>   ELSE
<std::string>   ELSIF
<std::string>   END
<std::string>   EXIT
<std::string>   FOR
<std::string>   IF
<std::string>   IN
<std::string>   IS
<std::string>   LOOP
<std::string>   MOD
<std::string>   NOT
<std::string>   OF
<std::string>   OR
<std::string>   OUT
<std::string>   PROCEDURE
<std::string>   PROGRAM
<std::string>   READ
<std::string>   RECORD
<std::string>   RETURN
<std::string>   THEN
<std::string>   TO
<std::string>   TYPE
<std::string>   VAR
<std::string>   WHILE
<std::string>   WRITE

//operators
<std::string>   ASSIGN  ":="
<std::string>   PLUS    "+"
<std::string>   MINUS   "-"
<std::string>   MULT    "*"
<std::string>   DIVIDE  "/"
<std::string>   LT      "<"
<std::string>   LE      "<="
<std::string>   GT      ">"
<std::string>   GE      ">="
<std::string>   EQ      "="
<std::string>   NE      "<>"


//delimiters
<std::string>   LPAREN      "("
<std::string>   RPAREN      ")"
<std::string>   LBRACK      "["
<std::string>   RBRACK      "]"
<std::string>   LBRACE      "{"
<std::string>   RBRACE      "}"
<std::string>   COMMA       ","
<std::string>   COLON       ":"
<std::string>   SEMICOLON   ";"
<std::string>   DOT         "."
<std::string>   LSABRAC     "[<"
<std::string>   RSABRAC     ">]"
<std::string>   BACKSLASH   "\\"

//identifiers
<std::string>   ID          "identifier"

//constants
<std::string>   INTEGER     "integer"
<std::string>   REAL        "real"
<std::string>   STRING      "string"
;

%left OR;
%left AND;
%nonassoc EQ NE;
%nonassoc LT LE GT GE;
%left PLUS MINUS;
%left MULT DIVIDE MOD DIV;//binary operators
%right POS NEG NOT;//unary operators

%nterm
//program
<shared_ptr<Program> >                   program
<shared_ptr<Body> >                      body

//declarations
<shared_ptr<Declarations> >               declarations
<shared_ptr<Declarations> >               declaration
<shared_ptr<VarDeclarations> >           var_declarations
<shared_ptr<VarDeclaration> >            var_declaration 
<shared_ptr<TypeDeclarations> >          type_declarations
<shared_ptr<TypeDeclaration> >           type_declaration
<shared_ptr<ProcedureDeclarations> >     procedure_declarations
<shared_ptr<ProcedureDeclaration> >      procedure_declaration
<shared_ptr<FormalParameters> >          formal_parameters
<shared_ptr<FormalParameter> >           formal_parameter
<shared_ptr<TypeAnnotation> >            type_annotation
<shared_ptr<Type> >                      type
<shared_ptr<Components> >                components
<shared_ptr<Component> >                 component
<shared_ptr<Ids> >                       ids
<shared_ptr<Id> >                        id

//statements
<shared_ptr<Statements> >                statements
<shared_ptr<Statement>  >                 statement
<shared_ptr<ReadParameters>>            read_parameters
<shared_ptr<ActualParameters> >          actual_parameters
<shared_ptr<WriteParameters> >           write_parameters
<shared_ptr<ElifSections> >              elif_sections
<shared_ptr<ElifSection> >               elif_section
<shared_ptr<ElseSection> >               else_section
<shared_ptr<ForStep> >                   for_step  

//expressions
<shared_ptr<Expressions> >               expressions
<shared_ptr<Expression> >                expression
<shared_ptr<WriteExpressions> >          write_expressions
<shared_ptr<WriteExpression> >           write_expression
<shared_ptr<AssignExpressions> >         assign_expressions
<shared_ptr<AssignExpression> >          assign_expression
<shared_ptr<ArrayExpressions> >          array_expressions
<shared_ptr<ArrayExpression> >           array_expression
<shared_ptr<Number> >                    number
<shared_ptr<Integer> >                   integer
<shared_ptr<Real> >                      real
<shared_ptr<String> >                    string
<shared_ptr<Lvalues> >                   lvalues
<shared_ptr<Lvalue> >                    lvalue
<shared_ptr<ComponentValues> >           component_values
<shared_ptr<ArrayValues> >               array_values
;

%%
%start program;

//program
program:
    PROGRAM IS body SEMICOLON{
        $$ = make_shared<Program>(@$,$body);
        p_driver->SetProgram($$);
    }
| error body SEMICOLON{
        $$ = make_shared<Program>(@$,$body);
        p_driver->SetProgram($$);
        yyerrok;
    }
| error {$$ = nullptr;yyerrok;yyclearin;}
;

body:
    declarations BEGIN statements END{
        $$ = make_shared<Body>(@$,$declarations,$statements);
    }

//declarations

declaration:
    VAR var_declarations{
        $$ = $2;
        if($$) $$->SetLocation(@$);
    }
|   PROCEDURE procedure_declarations{
        $$ = $2;
        if($$) $$->SetLocation(@$);
    }
|   TYPE type_declarations{
        $$ = $2;
        if($$) $$->SetLocation(@$);
    }
;

declarations:
    %empty{
        $$ = make_shared<Declarations>(@$);
    }
| declarations declaration{
        $$ =$1;
        if($$) $$->InsertArray($2);
    }
;

var_declaration:
    ids type_annotation ASSIGN expression SEMICOLON{
        $$ = make_shared<VarDeclaration>(@$,$ids,$type_annotation,$expression);
    }
| error SEMICOLON{
    $$ = nullptr;
    yyerrok;
    }
;

var_declarations:
    var_declaration{
        $$ = make_shared<VarDeclarations>(@$);
        if($$) $$->Insert($1);
    }
|  var_declarations var_declaration{
        $$ = $1;
        if($$) $$->Insert($2);
    }
;

type_declaration:
    id IS type SEMICOLON{
        $$ = make_shared<TypeDeclaration>(@$,$id,$type);
    }
| error SEMICOLON{$$ = nullptr;yyerrok;}
;

type_declarations:
    type_declaration {
        $$ = make_shared<TypeDeclarations>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   type_declarations type_declaration{
        $$ = $1;
        if($$){
            $$->Insert($2);
        }
    }
;

procedure_declaration:
    id LPAREN formal_parameters RPAREN type_annotation IS body SEMICOLON{
        $$ = make_shared<ProcedureDeclaration>(@$,$id,$formal_parameters,$type_annotation,$body);
    }
|   id LPAREN formal_parameters RPAREN type_annotation error body SEMICOLON{
        $$ = make_shared<ProcedureDeclaration>(@$,$id,$formal_parameters,$type_annotation,$body);
        yyerrok;
    }
;

procedure_declarations:
    procedure_declaration{
        $$ = make_shared<ProcedureDeclarations>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|
    procedure_declarations procedure_declaration{
        $$ = $1;
        if($$){
            $$->Insert($2);
        }
    }
;

formal_parameter:
    ids COLON type{
        $$ = make_shared<FormalParameter>(@$,$ids,$type);
    }
;

formal_parameters:
    %empty{
        $$ = make_shared<FormalParameters>(@$);
    }
|   formal_parameter{
        $$ = make_shared<FormalParameters>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   formal_parameters SEMICOLON formal_parameter{
        $$ = $1;
        if($$){
            $$->Insert($3);
        }
    }
;

type:
    id{
        $$ = make_shared<IdType>(@$,$id);
    }
|   ARRAY OF type[el_type] {
        $$ = make_shared<ArrayType>(@$,$el_type);
    }
|   RECORD components END {
        $$ = make_shared<RecordType>(@$,$components); 
    }
;

type_annotation:
    COLON type{
        $$ = make_shared<TypeAnnotation>(@$,$type);
    }
|   %empty{
        $$ = nullptr;
    }
;

component:
    id COLON type SEMICOLON{
        $$ = make_shared<Component>(@$,$id,$type);
    }
|   error SEMICOLON { $$ = nullptr; yyerrok;}
;


components:
    component{
        $$ = make_shared<Components>(@$); if($$) $$->Insert($1);
    }
|    components component {
        $$ = $1; if($$) $$->Insert($2);
    }
;

id:
   ID {
    $$ = make_shared<Id>(@$,$1);
}
;

ids:
    id {
        $$ = make_shared<Ids>(@$);
        if($$) $$->Insert($1);
    }
|   ids COMMA id {
        $$ = $1; if($$) $$->Insert($3);
    }
;


//statements

statement:
    lvalue ASSIGN expression SEMICOLON{
        $$ = make_shared<AssignStatement>(@$,$lvalue,$expression);
    }
|   id LPAREN actual_parameters RPAREN SEMICOLON{
        $$ = make_shared<ProcedureCallStatement>(@$,$id,$actual_parameters);
    }
|   IF expression THEN statements elif_sections[elif] else_section[else] END SEMICOLON{
        $$ = make_shared<IfStatement>(@$,$expression,$statements,$elif,$else);
    }
|   READ LPAREN read_parameters RPAREN SEMICOLON{
        $$ = make_shared<ReadStatement>(@$,$read_parameters);
    }
|   WRITE LPAREN write_parameters RPAREN SEMICOLON{
        $$ = make_shared<WriteStatement>(@$,$write_parameters);
    }
|   WHILE expression DO statements END SEMICOLON{
        $$ = make_shared<WhileStatement>(@$,$expression,$statements);
    }
|   LOOP statements END SEMICOLON{
        $$ = make_shared<LoopStatement>(@$,$statements);
    }
|   FOR id ASSIGN expression[begin] TO expression[end] for_step[step] DO statements END SEMICOLON{
        $$ = make_shared<ForStatement>(@$,$id,$begin,$end,$step,$statements);
    }
|   RETURN expression SEMICOLON{
        $$ = make_shared<ReturnStatement>(@$,$expression);
    }
|   RETURN SEMICOLON{
        $$ = make_shared<ReturnStatement>(@$);
    }

|   EXIT SEMICOLON{
        $$ = make_shared<ExitStatement>(@$);
    }
|   error SEMICOLON{
        $$ = nullptr;
        yyerrok;
    }
;

statements:
    %empty {
        $$ = make_shared<Statements>(@$);
    }
|   statements statement {
        $$ = $1; if($$) $$->Insert($2);
    }
;

actual_parameters:
    %empty{
        $$ = make_shared<ActualParameters>(@$);
    }
|   expressions{
        $$ = make_shared<ActualParameters>(@$);
        if($$){
            $$->InsertArray($1);
        }
    }
;

read_parameters:
    lvalues {
        $$ = make_shared<ReadParameters>(@$);
        if($$){
            $$->InsertArray($1);
        }
    }
;

write_parameters:
    write_expressions {
        $$ = make_shared<WriteParameters>(@$);
        if($$){
            $$->InsertArray($1);
        }
    }
|   %empty{
        $$ = make_shared<WriteParameters>(@$);
    }
;

elif_section:
    ELSIF expression THEN statements{
        $$ = make_shared<ElifSection>(@$,$expression,$statements);
    }  
;

elif_sections:
    %empty{
        $$ = make_shared<ElifSections>(@$);
    }
|   elif_sections elif_section{
        $$ = $1;
        if($$){
            $$->Insert($2);
        }
    }   
;

else_section:
    %empty{
        $$ = nullptr;
    }
|   ELSE statements{
        $$ = make_shared<ElseSection>(@$,$statements);
    }
;

for_step:
    %empty{
        $$ = nullptr;
    }
|   BY expression{
        $$ = make_shared<ForStep>(@$,$expression);
    }
;

//expressions

expression:
    lvalue{
        $$ = make_shared<LvalueExpression>(@$,$1);
    }
|   number{
        $$ = make_shared<NumberExpression>(@$,$1);
    }
|   LPAREN expression RPAREN{
        $$ = make_shared<ParenthesisExpression>(@$,$2);
    }
|   PLUS expression %prec POS{ 
        $$ = make_shared<UnaryExpression>(@$,make_shared<Operator>(@1, $1),$2);
    } 
|   MINUS expression %prec NEG{
        $$ = make_shared<UnaryExpression>(@$,make_shared<Operator>(@1,$1),$2);
    }
|   NOT expression{
        $$ = make_shared<UnaryExpression>(@$,make_shared<Operator>(@1,$1),$2);
    }
|   expression PLUS expression {
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression MINUS expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression MULT expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression DIV expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression DIVIDE expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression MOD expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression AND expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression OR expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression EQ expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|  expression NE expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression LT expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression LE expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression GT expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   expression GE expression{
        $$ = make_shared<BinaryExpression>(@$,$1,make_shared<Operator>(@2,$2),$3);
    }
|   id LPAREN actual_parameters RPAREN{
        $$ = make_shared<ProcedureCallExpression>(@$,$1,$3);
    }
|   id LBRACE component_values RBRACE{
        $$ = make_shared<RecordConstructExpression>(@$,$1,$3);
    }
|   id LSABRAC array_values RSABRAC{
        $$ = make_shared<ArrayConstructExpression>(@$,$1,$3);
    }
;

expressions:
    expression{
        $$ = make_shared<Expressions>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   expressions COMMA expression{
        $$ = $1;
        if($$){
            $$->Insert($3);
        }
    }
;

write_expression:
    expression{
        $$ = make_shared<WriteExpression>(@$,$1);
    }
|    string {
        $$ = make_shared<WriteExpression>(@$,$1);
    }
;

write_expressions:
    write_expression{
        $$ = make_shared<WriteExpressions>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   write_expressions COMMA write_expression{
        $$ = $1;
        if($$){
            $$->Insert($3);
        }
    }
;

assign_expression:
    id ASSIGN expression{
        $$ = make_shared<AssignExpression>(@$,$id,$expression);
    }
;

assign_expressions:
    assign_expression{
        $$ = make_shared<AssignExpressions>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   assign_expressions SEMICOLON assign_expression{
        $$ = $1;
        if ($$) {
            $$->Insert($3);
        }
    }
;

array_expression:
    expression[v] {
        $$ = make_shared<ArrayExpression>(@$,$v);
    }
|   expression[n] OF expression[v] {
        $$ = make_shared<ArrayExpression>(@$,$v,$n);
    }
;

array_expressions:
    array_expression{
        $$ = make_shared<ArrayExpressions>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   array_expressions COMMA array_expression{
        $$ = $1;
        if($$){
            $$->Insert($3);
        }
    }
;

number:
    integer {
        $$ = make_shared<Number>(@$,$1);
    }
|   real{
        $$ = make_shared<Number>(@$,$1);
    }
;

integer:
    INTEGER {
        $$ = make_shared<Integer>(@$, $1);
    }
;

real:
    REAL {
        $$ = make_shared<Real>(@$, $1);
    }
;

string:
    STRING {
        $$ = make_shared<String>(@$, $1);
    }
;

lvalues:
    lvalue{
        $$ = make_shared<Lvalues>(@$);
        if($$){
            $$->Insert($1);
        }
    }
|   lvalues COMMA lvalue{
        $$ = $1;
        if($$){
            $$->Insert($3);
        }
    }
;

lvalue:
    id{
        $$ = make_shared<IdLvalue>(@$,$1);
    }
|   lvalue LBRACK expression RBRACK{
        $$ = make_shared<ArrayElementLvalue>(@$,$1,$3);
    }
|   lvalue DOT id{
        $$ = make_shared<RecordComponentLvalue>(@$,$1,$3);
    }
;

component_values:
    assign_expressions {
        $$ = make_shared<ComponentValues>(@$,$1);
    }
;

array_values:
    array_expressions {
        $$ = make_shared<ArrayValues>(@$,$1);
    }
;
%%

void yy::Parser::error(const location_type& l, const std::string& m) {
    Logger::Error(m,&l);
    Logger::Error(m,&l,p_driver->ofs());
}


