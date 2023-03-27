/** Rational Calculator: Rational expression class implementation.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#include <iostream>
#include <cctype>
using namespace std;

RationalExpression::RationalExpression (): _knownRatio(0), _operator('/'), _leftOperand(0), _rightOperand(0) {}

RationalExpression::RationalExpression (RationalExpression&& temp):
    _knownRatio(temp._knownRatio), _operator(temp._operator), _leftOperand(temp._leftOperand), _rightOperand(temp._rightOperand) {
    temp._knownRatio = 0;
    temp._operator = 0;
    temp._leftOperand = 0;
    temp._rightOperand = 0;
}

RationalExpression& RationalExpression:: operator = (RationalExpression&& temp)	{
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

Ratio * RationalExpression::getRatio() {
    return _knownRatio;
}


// Takes an array of tokens with a relevant range. Interprets the part of the array within the relevant range as a rational expression. Returns that expression.
void RationalExpression::interpret (string * token, int first, int last)	{
	int operandsCount = 0;
	for (int i = first; i <= last; i++)	{
		if ((token[i] == "+") || (token[i] == "-") || (token[i] == "*") || (token[i] == "/"))	{
			_operator = token[i][0];

		} else if (token[i] == "(")	{
			int operandFirstIndex = i + 1;
			int operandLastIndex;
			int parenthesisCount = 1;
			for (int j = i+1; j <= last; j++)	{
				if (token[j] == "(") {
					parenthesisCount++;
				} else if (token[j] == ")")	{
					parenthesisCount--;
					if (parenthesisCount == 0)	{
						operandLastIndex = j - 1;
						i = j + 1;
						break;  //out of for(j...)
					}
				}
			}
			if (operandsCount == 0)	{
				_leftOperand = new RationalExpression();
				_leftOperand->interpret(token, operandFirstIndex, operandLastIndex);

			} else if (operandsCount == 1)	{
				_rightOperand = new RationalExpression();
				_rightOperand->interpret(token, operandFirstIndex, operandLastIndex);
			}
			operandsCount++;
		} else if (isdigit(token[i][0])) {
				int64_t top = (int64_t)stoi(token[i]);
				Ratio * ratio = new Ratio(top);
				RationalExpression * rexKnown = new RationalExpression();
				rexKnown->_knownRatio = ratio;
			if (operandsCount == 0)	{
				_leftOperand = rexKnown;
			} else if (operandsCount == 1)	{
				_rightOperand = rexKnown;
			}
			operandsCount++;
		}
	}
}


// Takes an expression without a known ratio and returns one without operands.
void RationalExpression::evaluate () {
	if (_leftOperand->_leftOperand != 0) {
		_leftOperand->evaluate();	
	}
	if (_rightOperand->_leftOperand != 0) {
		_rightOperand->evaluate();	
	}

	Ratio leftKnown = *(_leftOperand->_knownRatio);
	Ratio rightKnown = *(_rightOperand->_knownRatio);
	_knownRatio = new Ratio();

	switch (_operator) {
	case '+':
		*_knownRatio = leftKnown + rightKnown;
		break;
	case '-':
		*_knownRatio = leftKnown - rightKnown;
		break;
	case '*':
		*_knownRatio = leftKnown * rightKnown;
		break;
	case '/':
		*_knownRatio = leftKnown / rightKnown;
		break;
	}
	_knownRatio->reduce();

	delete _leftOperand, delete _rightOperand;
	_leftOperand = 0;
	_rightOperand = 0;
}


// Prints a Rational expression out to the console
void RationalExpression::print ()	{
    cout << "Rex Known Ratio: ";
	if(_knownRatio)	{
    	cout << *_knownRatio << endl;;
	} else {
		cout << "NULL." << endl;
	}

	cout << "Rex Operator: " << _operator << endl;

    cout << "Rex Left Operand address: " << _leftOperand << endl;
	if(_leftOperand)	{
    	cout << "Rex Left Operand value: "; _leftOperand->print(); cout << endl;
	}

    cout << "Rex Right Operand address: " << _rightOperand << endl;
	if(_rightOperand)	{
    	cout << "Rex Right Operand value: "; _rightOperand->print(); cout << endl;
	}
}


// Prints the enclosing expression
void RationalExpression::printEnclosing (string enclosing, int insertionPoint) {}