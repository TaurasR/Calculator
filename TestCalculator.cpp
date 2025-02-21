#include <gtest/gtest.h>
#include "Parser.h"

// Test simple addition
TEST(CalculatorTest, Addition) {
    INode* expr = Parser::parse("4+5");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 9);
    delete expr;
}

// Test simple subtraction
TEST(CalculatorTest, Subtraction) {
    INode* expr = Parser::parse("10-3");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 7);
    delete expr;
}

// Test multiplication
TEST(CalculatorTest, Multiplication) {
    INode* expr = Parser::parse("3*6");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 18);
    delete expr;
}

// Test division
TEST(CalculatorTest, Division) {
    INode* expr = Parser::parse("12/4");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 3);
    delete expr;
}

// Test variable usage
TEST(CalculatorTest, Variables) {
    INode* expr = Parser::parse("x+2*3");
    std::map<std::string, double> variables;
    variables["x"] = 5;
    EXPECT_EQ(expr->calc(variables), 11);
    delete expr;
}

// Test operator precedence
TEST(CalculatorTest, OperatorPrecedence) {
    INode* expr = Parser::parse("2+3*4");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 14); // 2 + (3 * 4)
    delete expr;
}

// Test parentheses
TEST(CalculatorTest, Parentheses) {
    INode* expr = Parser::parse("(2+3)*4");
    std::map<std::string, double> variables;
    EXPECT_EQ(expr->calc(variables), 20); // (2+3) * 4
    delete expr;
}

// Test division by zero
TEST(CalculatorTest, DivisionByZero) {
    INode* expr = Parser::parse("10/0");
    std::map<std::string, double> variables;
    EXPECT_THROW(expr->calc(variables), std::runtime_error);
    delete expr;
}
