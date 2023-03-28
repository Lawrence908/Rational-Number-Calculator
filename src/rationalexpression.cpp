/** Rational Calculator: Rational expression class implementation.
 *
 *  @file rationalexpression.cpp
 *  @brief Implementation of the RationalExpression class declared in rationalexpression.h.
 * 
 *  In this implementation file, comments will shorten RationalExpression to Rex. The notation (ratio operator leftOperand rightOperand) is used to represent the elements of a Rex.
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#include <iostream>
#include <cctype>
using namespace std;


/** @brief Default constructor. Makes a Rex of the form (null * null null).
 */
RationalExpression::RationalExpression (): _knownRatio(0), _operator('*'), _leftOperand(0), _rightOperand(0) {}


/** @brief Ratio constructor. Makes a Rex of the form (ratio / null null).
 */
RationalExpression::RationalExpression (Ratio * ratio): _knownRatio(ratio), _operator('/'), _leftOperand(0), _rightOperand(0) {}


/** @brief Move constructor. Takes the elements of an r-valued Rex and transfers them to this Rex.
 */
RationalExpression:: RationalExpression (RationalExpression && temp):
	_knownRatio(temp._knownRatio), _operator(temp._operator), _leftOperand(temp._leftOperand), _rightOperand(temp._rightOperand) {
	temp._knownRatio = 0;
	temp._operator = 0;
	temp._leftOperand = 0;
	temp._rightOperand = 0;
}


/** @brief Move assignment operator. Takes the elements of an r-valued Rex and transfers them to this Rex.
 */
RationalExpression & RationalExpression:: operator = (RationalExpression && temp) {
	_knownRatio = temp._knownRatio;
	_operator = temp._operator;
	_leftOperand = temp._leftOperand;
	_rightOperand = temp._rightOperand;
	temp._knownRatio = 0;
	temp._operator = 0;
	temp._leftOperand = 0;
	temp._rightOperand = 0;
	return *this;
}


/** @brief Ratio getter. Gets this Rex's known ratio pointer.
 */
Ratio * RationalExpression:: getRatio() {
	return _knownRatio;
}


/** @brief Ratio setter. Sets this Rex's known ratio pointer.
 */
void RationalExpression:: setRatio(Ratio * ratio) {
	_knownRatio = ratio;
}


/** @brief Gives whether this Rex has a particular operand.
 * @return True if this Rex has the named operand. False otherwise.
 */
bool RationalExpression:: hasLeft() {
	return !!_leftOperand;
}
bool RationalExpression:: hasRight() {
	return !!_rightOperand;
}


/** @brief Token-interpreting "constructor".
 * Takes an array of tokens with a relevant range. Interprets the part of the array within the relevant range as the elements of a Rex. Gives those elements to this Rex. Recursively constructs this Rex's left and right operands the same way.
 */
void RationalExpression:: interpret (string * token, int first, int last) {
	int operandsCount = 0;
	for (int i = first; i <= last; i++) {
		if ((token[i] == "+") || (token[i] == "-")
		 || (token[i] == "*") || (token[i] == "/")) {
			_operator = token[i][0];

		} else if (isdigit(token[i][0])) {
			int64_t top = (int64_t)stoi(token[i]);
			Ratio * ratio = new Ratio(top);
			RationalExpression * rexKnown = new RationalExpression(ratio);
			if (operandsCount == 0)
				_leftOperand = rexKnown;
			if (operandsCount == 1)
				_rightOperand = rexKnown;
			operandsCount++;

		} else if (token[i] == "(") {
			int operandFirstIndex = i + 1;
			int operandLastIndex = matchingParenthesis(token, operandFirstIndex, last);
			i = operandLastIndex + 2;
			if (operandsCount == 0) {
				_leftOperand = new RationalExpression();
				_leftOperand->interpret(token, operandFirstIndex, operandLastIndex);

			} else if (operandsCount == 1) {
				_rightOperand = new RationalExpression();
				_rightOperand->interpret(token, operandFirstIndex, operandLastIndex);
			}
			operandsCount++;
		}
	}
}

/** @brief Finds the matching closing parenthesis.
 * Non-member helper to RationalExpression. From a first token in an operand, finds the last token in the operand by matching up parentheses.
 * @param token The array of tokens.
 * @param first The first index of the operand.
 * @param last The last possible index.
 * @return The index of the token just before the matching closing parenthesis.
 */
int matchingParenthesis (string * token, int first, int last) {
	int parenthesisCount = 1;
	int j;
	for (j = first; j <= last; j++) {
		if (token[j] == "(")
			parenthesisCount++;
		if (token[j] == ")")
			parenthesisCount--;
		if (parenthesisCount == 0)
			break;
	}
	return j - 1;
}


/** @brief Evaluates a Rex that has one or two operands.
 * Operates on a Rex that has a left operand and possibly a right operand. Transforms this Rex, simplifying it until it has a known ratio instead, according to rational arithmetic. If there are both operands, a binary operation is performed. If there is only the left operand, a unary operation is performed.
 * Recursively evaluates this Rex's left and right operands the same way. Destructs this Rex's left and right operands when finished with them.
 */
void RationalExpression:: evaluate () {
	Ratio leftRatio;
	Ratio rightRatio;
	if (_leftOperand->hasLeft())
		_leftOperand->evaluate();
	if (hasRight()) {
		if (_rightOperand->hasLeft())
			_rightOperand->evaluate();
		// Binary operation: the operator acts on the left and right operands.
		leftRatio = *(_leftOperand->_knownRatio);
		rightRatio = *(_rightOperand->_knownRatio);
	} else {
		// Unary operation: the operator acts on the identity element and the left operand. For addition and subtraction, the identity element is 0/1. For multiplication and division, the identity element is 1/1.
		if ((_operator == '+') || (_operator == '-'))
			leftRatio = Ratio(0);
		if ((_operator == '*') || (_operator == '/'))
			leftRatio = Ratio(1);
		rightRatio = *(_leftOperand->_knownRatio);
	}

	_knownRatio = new Ratio();
	switch (_operator) {
	case '+':
		*_knownRatio = leftRatio + rightRatio;
		break;
	case '-':
		*_knownRatio = leftRatio - rightRatio;
		break;
	case '*':
		*_knownRatio = leftRatio * rightRatio;
		break;
	case '/':
		*_knownRatio = leftRatio / rightRatio;
		break;
	}
	_knownRatio->reduce();

	delete _leftOperand->_knownRatio;
	delete _leftOperand;
	_leftOperand = 0;
	if (hasRight()) {
		delete _rightOperand->_knownRatio;
		delete _rightOperand;
		_rightOperand = 0;
	}
}


// Prints a Rational expression out to the console
void RationalExpression:: print () {
	cout << "Rex Known Ratio: ";
	if(_knownRatio) {
		cout << *_knownRatio << endl;;
	} else {
		cout << "NULL." << endl;
	}

	cout << "Rex Operator: " << _operator << endl;

	cout << "Rex Left Operand address: " << _leftOperand << endl;
	if(_leftOperand) {
		cout << "Rex Left Operand value: "; _leftOperand->print(); cout << endl;
	}

	cout << "Rex Right Operand address: " << _rightOperand << endl;
	if(_rightOperand) {
		cout << "Rex Right Operand value: "; _rightOperand->print(); cout << endl;
	}
}


// Prints the enclosing expression
void RationalExpression:: printEnclosing (string enclosing, int insertionPoint) {}