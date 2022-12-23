%{
    #include "lexer.h"

    #include <string>
    #include <stdexcept>
    #include <unordered_map>

    #include "syntactic_parser.h"
    #include "driver.h"

    #define YY_USER_ACTION location.step(); location += YYLeng();

    using location_type = yy::Parser::location_type;
    using symbol_type = yy::Parser::symbol_type;
    using MakeTable = std::unordered_map<std::string, 
        symbol_type(*)(std::string s,location_type location)>;
    
    symbol_type make_INTEGER(const std::string& s,const location_type& location);
    symbol_type make_REAL(const std::string& s, const location_type& location);
    symbol_type make_STRING(const std::string& s, const location_type& location);
    void panic_UNTERM_STRING(const std::string& s, const location_type& location);
    symbol_type make_ID(const std::string& s, const location_type& location);
    symbol_type make_OPERATOR(const std::string& s, const location_type& location);
    symbol_type make_DELIMITER(const std::string& s, const location_type& location);
    void skip_COMMENTS(const std::string& s, const location_type& location);
    void panic_UNKNOWN_CHAR(const std::string& s, const location_type& location);
%}

%option c++
%option noyywrap
%option nounput
%option noinput
%option batch
%option debug

%x      COMMENT

WS                    ([ \t\r]+)
NEWLINE               \n

DIGIT                 [0-9]
INTEGER               ({DIGIT}+)
REAL                  ({DIGIT}+"."{DIGIT}*)
LETTER                [A-Za-z]
STRING                (\"[^\n"]*\")
UNTERM_STRING         (\"[^\n"]*)

IDENTIFIER            ({LETTER}({LETTER}|{DIGIT})*)
OPERATOR              (":="|"+"|"-"|"*"|"/"|"<"|"<="|">"|">="|"="|"<>")
DELIMITER             (":"|";"|","|"."|"("|")"|"["|"]"|"{"|"}"|"[<"|">]"|"\\")

COMMENTS_BEGIN        "(*"
COMMENTS_END          "*)"

%%

%{
  auto& location = drv_.location();
%}

<INITIAL><<EOF>>              { return yy::Parser::make_YYEOF(location); }
<INITIAL>{WS}                 /* skip whitespaces */
<INITIAL>{NEWLINE}            { location.lines(); }

<INITIAL>{INTEGER}            { return make_INTEGER(YYText(), location); }
<INITIAL>{REAL}               { return make_REAL(YYText(), location); }
<INITIAL>{STRING}             { return make_STRING(YYText(), location); }
<INITIAL>{UNTERM_STRING}      { panic_UNTERM_STRING(YYText(), location); }

<INITIAL>{IDENTIFIER}         { return make_ID(YYText(), location); }
<INITIAL>{OPERATOR}           { return make_OPERATOR(YYText(), location); }
<INITIAL>{DELIMITER}          { return make_DELIMITER(YYText(), location); }

<INITIAL>{COMMENTS_BEGIN}     { BEGIN(COMMENT); skip_COMMENTS(YYText(), location); }
<COMMENT>{COMMENTS_END}       { BEGIN(INITIAL); skip_COMMENTS(YYText(), location); }
<COMMENT>.                    { skip_COMMENTS(YYText(), location); }
<COMMENT>{NEWLINE}            { location.lines(); skip_COMMENTS(YYText(), location); }
<COMMENT><<EOF>>              { BEGIN(INITIAL); skip_COMMENTS("", location); }

<INITIAL>.                    { panic_UNKNOWN_CHAR(YYText(), location); }

%%

symbol_type make_INTEGER(const std::string& s, const location_type& location){
    try{
        std::stoi(s);
    }catch(const std::out_of_range& e){
        throw yy::Parser::syntax_error(location,"range error,integer out of range" + s);
    }
    return yy::Parser::make_INTEGER(s,location);
}

symbol_type make_REAL(const std::string& s, const location_type& location){
    return yy::Parser::make_REAL(s,location);
}

symbol_type make_STRING(const std::string& s, const location_type& location) {
  if (s.size() > 257) {
    throw yy::Parser::syntax_error(
        location, "value error, string literal is too long: " + s);
  }
  if(s.find('\t') != std::string::npos){
    throw yy::Parser::syntax_error(location,"value error, invalid character found in string: "+s);
  }
    return yy::Parser::make_STRING(s,location);
}

void panic_UNTERM_STRING(const std::string& s, const location_type& location){
    throw yy::Parser::syntax_error(location,"syntax error, unterminated string literal: " + s);
}

static const MakeTable make_keyword_table{
    {"AND", yy::Parser::make_AND},
    {"ARRAY", yy::Parser::make_ARRAY},
    {"BEGIN", yy::Parser::make_BEGIN},
    {"BY", yy::Parser::make_BY},
    {"DIV", yy::Parser::make_DIV},
    {"DO", yy::Parser::make_DO},
    {"ELSE", yy::Parser::make_ELSE},
    {"ELSIF", yy::Parser::make_ELSIF},
    {"END", yy::Parser::make_END},
    {"EXIT", yy::Parser::make_EXIT},
    {"FOR", yy::Parser::make_FOR},
    {"IF", yy::Parser::make_IF},
    {"IN", yy::Parser::make_IN},
    {"IS", yy::Parser::make_IS},
    {"LOOP", yy::Parser::make_LOOP},
    {"MOD", yy::Parser::make_MOD},
    {"NOT", yy::Parser::make_NOT},
    {"OF", yy::Parser::make_OF},
    {"OR", yy::Parser::make_OR},
    {"OUT", yy::Parser::make_OUT},
    {"PROCEDURE", yy::Parser::make_PROCEDURE},
    {"PROGRAM", yy::Parser::make_PROGRAM},
    {"READ", yy::Parser::make_READ},
    {"RECORD", yy::Parser::make_RECORD},
    {"RETURN", yy::Parser::make_RETURN},
    {"THEN", yy::Parser::make_THEN},
    {"TO", yy::Parser::make_TO},
    {"TYPE", yy::Parser::make_TYPE},
    {"VAR", yy::Parser::make_VAR},
    {"WHILE", yy::Parser::make_WHILE},
    {"WRITE", yy::Parser::make_WRITE},
};

symbol_type make_ID(const std::string& s, const location_type& location) {
  if (s.size() > 255) {
    throw yy::Parser::syntax_error(
        location, "compile error, identifier is too long: " + s);
  }

  auto entry = make_keyword_table.find(s);
    if (entry != make_keyword_table.end()) {
        return entry->second(s, location);
    }
    return yy::Parser::make_ID(s, location);
}

static const MakeTable make_operator_table{
    {":=", yy::Parser::make_ASSIGN},
    {"+", yy::Parser::make_PLUS},
    {"-", yy::Parser::make_MINUS},
    {"*", yy::Parser::make_MULT},
    {"/", yy::Parser::make_DIVIDE},
    {"<", yy::Parser::make_LT},
    {"<=", yy::Parser::make_LE},
    {">", yy::Parser::make_GT},
    {">=", yy::Parser::make_GE},
    {"=", yy::Parser::make_EQ},
    {"<>", yy::Parser::make_NE},
};

symbol_type make_OPERATOR(const std::string& s, const location_type& location) {
  auto entry = make_operator_table.find(s);
  if (entry != make_operator_table.end()) {
    return entry->second(s, location);
  }
  throw yy::Parser::syntax_error(location, "syntax error, unknown operator: " + s);
}

static const MakeTable make_delimiter_table{
    {".", yy::Parser::make_DOT},
    {",", yy::Parser::make_COMMA},
    {":", yy::Parser::make_COLON},
    {";", yy::Parser::make_SEMICOLON},
    {"(", yy::Parser::make_LPAREN},
    {")", yy::Parser::make_RPAREN},
    {"[", yy::Parser::make_LBRACK},
    {"]", yy::Parser::make_RBRACK},
    {"{", yy::Parser::make_LBRACE},
    {"}", yy::Parser::make_RBRACE},
    {"[<", yy::Parser::make_LSABRAC},
    {">]", yy::Parser::make_RSABRAC},
    {"\\", yy::Parser::make_BACKSLASH},
};

symbol_type make_DELIMITER(const std::string& s, const location_type& location) {
  auto entry = make_delimiter_table.find(s);
  if (entry != make_delimiter_table.end()) {
    return entry->second(s, location);
  }
  throw yy::Parser::syntax_error(location, "syntax error, unknown delimiter: " + s);
}

void skip_COMMENTS(const std::string& s, const location_type& location){
    //do nothing
    static std::string comments_buffer;
    static location_type comments_location;

    if(s == "(*"){
        comments_buffer = s;
        comments_location = location;
    }else if(!s.empty()){
        comments_buffer += s;
        comments_location += location;
    }else{
        throw yy::Parser::syntax_error(comments_location,"syntax error, unterminated comment: " + comments_buffer);
    }
}

void panic_UNKNOWN_CHAR(const std::string& s, const location_type& location){
    throw yy::Parser::syntax_error(location,"syntax error, unknown character: " + s);
}