//
// Created by Rohini Sharma on 5/3/20.
//

#include "expression_evaluation/Expression.h"
#include <exprtk.hpp>

using std::to_string;

namespace expression_evaluator {

Expression::Expression(const string& exp) {
  expression_str = exp;
}

typedef exprtk::expression<double> expression;
typedef exprtk::parser<double> parser;
string Expression::Evaluate() {
  parser exp_parser;
  expression exp_to_evaluate;
  if (!exp_parser.compile(expression_str, exp_to_evaluate)) {
    return "Could not evaluate expression";
  }
  return  to_string(exp_to_evaluate.value());
}
}
