/** Rational Calculator: Rational expression class.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#ifndef rationalexpression_h
#define rationalexpression_h

#include <stdio.h>
#include <string>
#include "ratio.h"
using namespace std;

class RationalExpression {
private:
  Ratio * _knownRatio;
  string _operator;
  RationalExpression * _leftOperand;
  RationalExpression * _rightOperand;
public:
  RationalExpression();
  ~RationalExpression() {}
  RationalExpression(RationalExpression&&);
  RationalExpression& operator = (RationalExpression&&);


  Ratio * getRatio();
  // string getOperator();
  // RationalExpression * getLeftOperand();
  // RationalExpression * getRightOperand();

  // void setRatio();
  // void setOperator();
  // void setLeftOperand();
  // void setRightOperand();


  // Takes a string, interprets it as a rational expression, and returns that expression.
  void interpret (string * token, int first, int last);

  // Takes an expression without a known ratio and returns one without operands.
  void evaluate ();

  // Prints the enclosing expression
  void print (string enclosing, int insertionPoint);


  // Prints a Rational expression out to the console
  void show ();

};

#endif