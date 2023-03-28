/** Rational Calculator
 *
 *  @file main.cpp
 *  @brief A calculator for rational number arithmetic.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date Feb 22, 2023
 */


// Included library, header, and source files.
#include <iostream>
#include <cstdint>
#include <regex>
#include <string>
#include <cctype>
#include "../include/ratio.h"
#include "../include/rationalexpression.h"
#include "rationalexpression.cpp"
using namespace std;


// Function declarations.
void tokenize (string input, string token[], int &tokenLength);


int main (int argc, char ** argv) {
	cout << "Rational Calculator v0.1." << endl;
	// Input from the shell or from a prompt.
	string input = "";
	if (argc > 2) {
		cout << "Usage: rc may take one shell argument. Use quotation marks." << endl;
		return 0;
	}
	if (argc == 2) {
		input = argv[1];
	} else {
		cout << "   rc > ";
		getline(cin, input);
	}

	// Calculator loop. An input starting with 'q' quits the program.
	while (tolower(input[0]) != 'q') {
		// For each input, we need a RationalExpression object to hold our interpretation of the string.
		RationalExpression rex;
		int inputLength = 0;
		while (input[inputLength])
			inputLength++;
		// The input length is the upper bound of tokens needed. Convert the input string into an array of token strings. Each token is one of the expression's lexical items: an integer, an operator, or a parenthesis.
		string token[inputLength];
		int tokenLength;
		tokenize(input, token, tokenLength);

		// Now that the input is tokenized, we use those tokens to build an arithmetic expression.
		rex.interpret(token, 0, tokenLength - 1);

		// If we have an expression with at least one operand, we evaluate, simplifying until it is an expression of a known ratio.
		if (rex.hasLeft())
			rex.evaluate();

		// Print the result.
		Ratio * result;
		if (rex.getRatio()) {
			result = rex.getRatio();
			cout << "Result: " << *result << endl;
		}

		// Get the next input and repeat.
		cout << "   rc > ";
		getline(cin, input);
	}
	return 0;
}


/**
 * @brief Breaks a string into tokens.
 * Breaks an input string into a sequence of tokens that are parts of an arithmetic expression. Each token is a string that is either one of the symbols +*-/() or numeric. Prints the sequence of tokens. Fills the token array with the sequence and counts the tokens.
 * @param input The input string.
 * @param token The array of token strings. Should start empty with an upper-bound size. Gets filled with the expression's tokens.
 * @param tokenLength The count of tokens. Passed and returned by value.
 */
void tokenize (string input, string token[], int & tokenLength) {
	regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");
	sregex_iterator it(input.begin(), input.end(), expr_regex);
	sregex_iterator end;
	int i = 0;
	cout << "Tokens: ";
	while (it != end) {
		token[i] = it->str();
		cout << token[i] << " ";
		it++;
		i++;
	}
	cout << endl;
	tokenLength = i;
}