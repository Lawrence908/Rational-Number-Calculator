/** Rational Calculator
 *
 *  @file main.cpp
 *  @brief A calculator for rational number arithmetic.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */


// Includes

#include <iostream>
#include <cstdint>
#include <regex>
#include <string>
#include <stdio.h>
using namespace std;


int64_t gcd(int64_t a, int64_t b);


class Ratio {
private:
	int64_t top;     // The numerator.
	int64_t bottom;  // The denominator.
public:
    /** @brief Default constructor. Returns the ratio 0/1. */
    Ratio (): top(0), bottom(1) {}

    /** @brief Integer constructor. Given n, returns the ratio n/1. */
    Ratio (int64_t integer): top(integer), bottom(1) {}

    /** @brief Fraction constructor. Given p and q, returns the ratio p/q. */
    Ratio (int64_t p, int64_t q): top(p), bottom(q) {};

    /** @brief Destructor. */
    ~Ratio () {}

    // /** @brief Returns whether a ratio's denominator is zero. */
    // bool dividesByZero () {
    //     return !bottom;
    // }

    /** @brief Reduces a ratio.
     * 
     * Converts a ratio to its reduced ratio. Makes the denominator positive. Finds the GCD of top and bottom. In place, divides top and bottom by the GCD.
     */
    void reduce () {
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
        int64_t greatestDivisor = gcd(top, bottom);
        top = top / greatestDivisor;
        bottom = bottom / greatestDivisor;
    }

    void print () {
        cout << top << " / " << bottom << endl;
    }

    /** @brief Gives RationalExpression access to Ratio. Only a RationalExpression can get and set in a Ratio. */
    friend class RationalExpression;
};


/**
 * @brief Finds the greatest common divisor of two integers by Euclid's algorithm.
 * @param a, b Integers.
 * @return The greatest common divisor of a, b.
 */
int64_t gcd(int64_t a, int64_t b) {
    int64_t q;
    int64_t r = 1;
    while (r != 0) {
        q = a / b;
        r = a - (q * b);
        if (r == 0)
            return abs(b);
        a = b;
        b = r;
    }
    return 0;
}


class RationalExpression {
private:
  Ratio * knownRatio;
  string operation;
  RationalExpression * leftOperand;
  RationalExpression * rightOperand;
public:
  RationalExpression();
  ~RationalExpression() {}
  RationalExpression(RationalExpression&&);

  Ratio * getRatio();
  string getOperation();
  RationalExpression * getLeftOperand();
  RationalExpression * getRightOperand();

  void setRatio();
  void setOperation();
  void setLeftOperand();
  void setRightOperand();


  // Takes a string, interprets it as a rational expression, and returns that expression.
  void interpret (string * token, int first, int last);

  // Takes an expression without a known ratio and returns one without operands.
  void evaluate ();

  // Prints the enclosing expression
  void print (string enclosing, int insertionPoint);


  // Prints a Rational expression out to the console
  void showRex (RationalExpression * rex)	{
    cout << "Rex Known Ratio: " << endl;
    rex->knownRatio->print();
    cout << "Rex Left Operand: " << rex->leftOperand << endl;
    cout << "Rex Operation: " << rex->operation << endl;
    cout << "Rex Right Operand: " << rex->rightOperand << endl;
    return;
  }

};

RationalExpression::RationalExpression (): knownRatio(0), operation("/"), leftOperand(0), rightOperand(0) {}
RationalExpression::RationalExpression (RationalExpression&& temp):
    knownRatio(temp.knownRatio), operation(temp.operation), leftOperand(temp.leftOperand), rightOperand(temp.rightOperand) {
    temp.knownRatio = 0;
    temp.operation = "";
    temp.leftOperand = 0;
    temp.rightOperand = 0;
}

Ratio * RationalExpression::getRatio() {
    return knownRatio;
}

string RationalExpression::getOperation() {}
RationalExpression * RationalExpression::getLeftOperand() {}
RationalExpression * RationalExpression::getRightOperand() {}

void RationalExpression::setRatio() {}
void RationalExpression::setOperation() {}
void RationalExpression::setLeftOperand() {}
void RationalExpression::setRightOperand() {}


// Takes a string with arithmetic in S-expression form, interprets it as a rational expression, and returns that expression.
void RationalExpression::interpret (string * token, int first, int last)	{
	RationalExpression rex;

	rex.knownRatio = NULL;
	int operandsCount = 0;
	for (int i = first; i <= last; i++)	{
		if (token[i] == ")")	{
			return;
		}
		if ((token[i] == "+") || (token[i] == "-") || (token[i] == "*") || (token[i] == "/"))	{
			rex.operation = token[i];
cout << token[i] << endl;
cout << rex.operation << endl;

		} else if (token[i] == "(")	{
			int operandFirst = i + 1;
			int operandLast;
			int parenthesisCount = 1;
			for (int j = i+1; j <= last; j++)	{
				if (token[j] == "(") {
					parenthesisCount++;
				} else if (token[j] == ")")	{
					parenthesisCount--;
					if (parenthesisCount == 0)	{
						operandLast = j - 1;
						break;  //out of for(j...)
					}
				}
			}
			if (operandsCount == 0)	{
				rex.leftOperand->interpret(token, operandFirst, operandLast);

			} else if (operandsCount == 1)	{
				rex.rightOperand->interpret(token, operandFirst, operandLast);
			}
cout << "operandsCount++" << endl;
			operandsCount++;
		} else {
				Ratio ratio;
				ratio.top = stoi(token[i]);
cout << stoi(token[i]) << endl;
				ratio.bottom = 1;
				RationalExpression rexKnown;
				rexKnown.knownRatio = &ratio;
				rexKnown.operation = "/";
				rexKnown.leftOperand = NULL;
				rexKnown.rightOperand = NULL;
			if (operandsCount == 0)	{
				rex.leftOperand = &rexKnown;
cout << "rex.leftOperand = " << rexKnown.knownRatio->top << endl;
			} else if (operandsCount == 1)	{
				rex.rightOperand = &rexKnown;
cout << "rex.rightOperand = " << rexKnown.knownRatio->top << endl;
			}
cout << "operandsCount++" << endl;
			operandsCount++;
cout << "Iterating i" << endl;
		}
	}
}


// Takes an expression without a known ratio and returns one without operands.
void RationalExpression::evaluate () {
}

// Prints the enclosing expression
void RationalExpression::print (string enclosing, int insertionPoint) {
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, int length, string token[]);



int main ()	{
	RationalExpression rex;

	string input;

	cout << "Enter an arithmetic expression:" << endl;

	getline(cin, input);
	
	int length = 0;
	while (input[length])	{
		length++;
	}
	
	string token[length];
	tokenize(input, length, token);
	rex.interpret(token, 1, length - 2);  //strip off parentheses

cout << "EXIT generate" << endl;

cout << "Onwards to evaluate" << endl;

	rex.evaluate();

	Ratio * result;
	if (rex.getRatio())	{
		result = rex.getRatio();
		result->print();
	} else {
		
	}


	return 0;
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, int length, string token[])	{
	regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");
	
	sregex_iterator it(input.begin(), input.end(), expr_regex);
	sregex_iterator end;
	
	int i=0;
	
	while (it != end)	{
		token[i] = it->str();
		cout << token[i] << " ";
		it++;
		i++;
	}
	cout << endl;
}

