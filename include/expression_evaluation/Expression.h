//
// Created by Rohini Sharma on 5/3/20.
//

#ifndef FINALPROJECT_EXPRESSION_H
#define FINALPROJECT_EXPRESSION_H

#include <string>
#include <exprtk.hpp>
using std::string;

namespace expression_evaluator {

class Expression {

 public:
  /**
   * Creates an expression object from a string that contains a mathematical
   * expression
   * @param exp_string The string containing a mathematical expression
   */
  explicit Expression(const string& exp_string);
  /**
   * Evaluates the expression string and returns a string with the answer
   * @return The answer to the expression, or returns "Could not evaluate expression"
   * if the expression is invalid. Returned expression has 5 decimal places.
   */
  string Evaluate();

 private:
  /** String of the expression passed in to the constructor **/
  string expression_str;
};
}


#endif  // FINALPROJECT_EXPRESSION_H
