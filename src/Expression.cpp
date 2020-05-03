//
// Created by Rohini Sharma on 5/3/20.
//

#include "expression_evaluation/Expression.h"
#include <exprtk.hpp>


namespace expression_evaluator {

Expression::Expression(const string& exp) {
  expression_str = exp;
}

double Expression::Evaluate() {
  parser exp_parser;
  expression exp_to_evaluate;
  if (!exp_parser.compile(expression_str, exp_to_evaluate)) {
    throw "Could not evaluate expression";
  }
  return exp_to_evaluate.value();
}
}
