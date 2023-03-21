#include "rationalexpression.h"

RationalExpression::RationalExpression (): knownRatio(0), operation("/"), leftOperand(0), rightOperand(0) {}
RationalExpression::RationalExpression (RationalExpression&&) {

}

Ratio RationalExpression::getRatio() {}
string RationalExpression::getOperation() {}
RationalExpression * RationalExpression::getLeftOperand() {}
RationalExpression * RationalExpression::getRightOperand() {}

void RationalExpression::setRatio() {}
void RationalExpression::setOperation() {}
void RationalExpression::setLeftOperand() {}
void RationalExpression::setRightOperand() {}


// Takes a string, interprets it as a rational expression, and returns that expression.
RationalExpression RationalExpression::interpret (string * token, int first, int last) {
    return RationalExpression();
}

// Takes an expression without a known ratio and returns one without operands.
RationalExpression RationalExpression::evaluate (RationalExpression rex) {
    return RationalExpression();
}

// Prints the enclosing expression
RationalExpression RationalExpression::print (string enclosing, int insertionPoint) {
    return RationalExpression();
}
