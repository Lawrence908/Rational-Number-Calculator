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

class RationalExpression {
private:
  Ratio * knownRatio;
  string operation;
  RationalExpression * leftOperand;
  RationalExpression * rightOperand;
public:
  RationalExpression();
  ~RationalExpression();

  Ratio getRatio();
  string getOperation();
  RationalExpression * getLeftOperand();
  RationalExpression * getRightOperand();

  void setRatio();
  void setOperation();
  void setLeftOperand();
  void setRightOperand();

  RationalExpression generateExpression();
};

#endif