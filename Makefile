TARGET := syntactic_paser

BIN_DIR := bin
BUILD_DIR := build
SRC_DIR := src
OUT_DIR := output

LEX_IN := $(SRC_DIR)/lexer.lex
LEX_SRC := $(SRC_DIR)/lexer.cpp

YACC_IN := $(SRC_DIR)/syntactic_parser.yy
YACC_SRC := $(SRC_DIR)/syntactic_parser.cpp
YACC_H := $(SRC_DIR)/syntactic_parser.h $(SRC_DIR)/location.h

SRCS := $(YACC_SRC) $(LEX_SRC) $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

LEX := flex
YACC := bison
CXX := g++
CXXFLAGS := -g -Wall -O3 -std=c++17 -MMD
MKDIR := mkdir -p
RM := rm -rf

.PHONY: start clean

start: $(BIN_DIR)/$(TARGET)
	@$(MKDIR) $(OUT_DIR)
	@$< $(INPUT)

$(BIN_DIR)/$(TARGET): $(OBJS)
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.cpp.o: %.cpp
	@$(MKDIR) $(dir $@)
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(LEX_SRC): $(LEX_IN)
	@$(LEX) -o $@ $<

$(YACC_SRC): $(YACC_IN)
	@$(YACC) -o $@ -d $<

$(YACC_H): $(YACC_SRC)

-include $(DEPS)

clean:
	@$(RM) $(BIN_DIR) $(BUILD_DIR) $(LEX_SRC) $(YACC_SRC) $(YACC_H)