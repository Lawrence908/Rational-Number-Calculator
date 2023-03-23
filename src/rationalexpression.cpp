#include <iostream>
using namespace std;

RationalExpression::RationalExpression (): _knownRatio(0), _operator("/"), _leftOperand(0), _rightOperand(0) {}
RationalExpression::RationalExpression (RationalExpression&& temp):
    _knownRatio(temp._knownRatio), _operator(temp._operator), _leftOperand(temp._leftOperand), _rightOperand(temp._rightOperand) {
    temp._knownRatio = 0;
    temp._operator = "";
    temp._leftOperand = 0;
    temp._rightOperand = 0;
}

RationalExpression& RationalExpression:: operator = (RationalExpression&& temp)	{
	_knownRatio = temp._knownRatio;
	_operator = temp._operator;
	_leftOperand = temp._leftOperand;
	_rightOperand = temp._rightOperand;
	temp._knownRatio = 0;
    temp._operator = "";
    temp._leftOperand = 0;
    temp._rightOperand = 0;

	return *this;
}

Ratio * RationalExpression::getRatio() {
    return _knownRatio;
}

// string RationalExpression::getOperator() {}
// RationalExpression * RationalExpression::getLeftOperand() {}
// RationalExpression * RationalExpression::getRightOperand() {}

// void RationalExpression::setRatio() {}
// void RationalExpression::setOperator() {}
// void RationalExpression::setLeftOperand() {}
// void RationalExpression::setRightOperand() {}


// Takes a string with arithmetic in S-expression form, interprets it as a rational expression, and returns that expression.
void RationalExpression::interpret (string * token, int first, int last)	{
	int operandsCount = 0;
	for (int i = first; i <= last; i++)	{
		if ((token[i] == "+") || (token[i] == "-") || (token[i] == "*") || (token[i] == "/"))	{
			_operator = token[i];

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
		} else {
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
		
}

// Prints the enclosing expression
void RationalExpression::print (string enclosing, int insertionPoint) {
}

  // Prints a Rational expression out to the console
  void RationalExpression::show ()	{
    cout << "Rex Known Ratio: ";
	if(_knownRatio)	{
    	_knownRatio->print();
	} else {
		cout << "NULL." << endl;
	}

	cout << "Rex Operator: " << _operator << endl;

    cout << "Rex Left Operand address: " << _leftOperand << endl;
	if(_leftOperand)	{
    	cout << "Rex Left Operand value: "; _leftOperand->show(); cout << endl;
	}

    cout << "Rex Right Operand address: " << _rightOperand << endl;
	if(_rightOperand)	{
    	cout << "Rex Right Operand value: "; _rightOperand->show(); cout << endl;
	}
    return;
  }