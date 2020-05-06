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

TEST_CASE("Multi digit expressions") {
  SECTION("Addition") {
    Expression exp("33 + 66");
    REQUIRE(exp.Evaluate() == "99.000000");
  }
  SECTION("Subtraction") {
    Expression exp("66 - 33");
    REQUIRE(exp.Evaluate() == "33.000000");
  }

  SECTION("Multiplication") {
    Expression exp("12 * 15");
    REQUIRE(exp.Evaluate() == "180.000000");
  }

  SECTION("Division") {
    Expression exp("33 / 11");
    REQUIRE(exp.Evaluate() == "3.000000");
  }
}

TEST_CASE("Invalid expressions") {
  SECTION("Nonsensical order of symbols") {
    Expression exp("(+)");
    REQUIRE(exp.Evaluate() == "Could not evaluate expression");
  }

  SECTION("Multiple operations in a row") {
    Expression exp("3 ** 5");
    REQUIRE(exp.Evaluate() == "Could not evaluate expression");
  }

  SECTION("Empty expression") {
    Expression exp("");
    REQUIRE(exp.Evaluate() == "Could not evaluate expression");
  }
  SECTION("Blank expression") {
    Expression exp("       ");
    REQUIRE(exp.Evaluate() == "Could not evaluate expression");
  }
}

