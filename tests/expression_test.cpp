//
// Created by Rohini Sharma on 5/3/20.
//

#include <catch2/catch.hpp>
#include <expression_evaluation/Expression.h>

using expression_evaluator::Expression;

TEST_CASE("Simple operation expressions") {

  SECTION("Addition") {
    Expression exp("3 + 5");
    REQUIRE(exp.Evaluate() == "8.000000");
  }

  SECTION("Subtraction") {
    Expression exp("5 - 3");
    REQUIRE(exp.Evaluate() == "2.000000");
  }

  SECTION("Multiplication") {
    Expression exp("5 * 3");
    REQUIRE(exp.Evaluate() == "15.000000");
  }

  SECTION("Division") {
    Expression exp(" 6 / 3");
    REQUIRE(exp.Evaluate() == "2.000000");
  }

}

TEST_CASE("Solves expression according to order of equations") {
  Expression exp("3 * 7 + 8");
  REQUIRE(exp.Evaluate() == "29.000000");
}

TEST_CASE("Solves equation with grouping symbols") {

  SECTION("Parentheses") {
    Expression exp("5 * (3+4)");
    REQUIRE(exp.Evaluate() == "35.000000");
  }

  SECTION("Brackets") {
    Expression exp("5 * [3 + 4]");
    REQUIRE(exp.Evaluate() == "35.000000");
  }

}


