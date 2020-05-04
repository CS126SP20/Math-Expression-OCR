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
  Expression(const string& exp_string);
  string Evaluate();

 private:
  string expression_str;
  typedef exprtk::expression<double> expression;
  typedef exprtk::parser<double> parser;



};
}


#endif  // FINALPROJECT_EXPRESSION_H
