//Copyright 2021
#include "Infix_Evaluator.h"


const int Infix_Evaluator::PRECEDENCE[] = { 1,1,2,2,2,3 };
const std::string Infix_Evaluator::OPERATORS = "+-*/%^";
int rhs = 0;
int lhs = 0;

Infix_Evaluator::Infix_Evaluator() {

}
Infix_Evaluator::~Infix_Evaluator() {

}

/** Evaluates a infix expression.
		@param expression The expression to be evaluated
		@return The value of the expression
		@throws Syntax_Error if a syntax error is detected
*/
int Infix_Evaluator::eval(const std::string &expression) {
	
	char currentItem;
	for (int i = 0; i < expression.size(); i++) {
		currentItem = expression[i];
		if (isdigit(currentItem)) {
			int total = 0;
			while (isdigit(currentItem)) {
				total = total * 10 + (currentItem - '0');
				i++;
				if (i < expression.length()) {
					currentItem = expression[i];
				} else {
					break;
				}
			}
			i--;
			operand_stack.push(total);
		} else if (currentItem == '(') {
			operator_stack.push(currentItem);
		} else if (currentItem == ')') {
			while (operator_stack.top() != '(') {
				eval_op(operator_stack.top());
			}
			operator_stack.pop();
		} else if (is_operator(currentItem)) {
			while (!operator_stack.empty() && precedence(currentItem) <= precedence(operator_stack.top())) {
				eval_op(operator_stack.top());
			}
			operator_stack.push(currentItem);
		}
		
	}
	while (!operator_stack.empty()) {
		eval_op(operator_stack.top());
	}
	return operand_stack.top();



}

/** Evaluates the current operator.
		This function pops the two operands off the operand
		stack and applies the operator.
		@param op A character representing the operator
		@throws Syntax_Error if top is attempted on an empty stack
*/
void Infix_Evaluator::eval_op(char op) {
	
	rhs = operand_stack.top();
	operand_stack.pop();
	lhs = operand_stack.top();
	operand_stack.pop();
	process_operator(op);

}

void Infix_Evaluator::process_operator(char op) {

	int final = 0;
	if (op == '+') {
		final = lhs + rhs;
		operator_stack.pop();
	} else if (op == '-') {
		final = lhs - rhs;
		operator_stack.pop();
	} else if (op == '*') {
		final = lhs * rhs;
		operator_stack.pop();
	} else if (op == '/') {
		final = lhs / rhs;
		operator_stack.pop();
	} else if (op == '%') {
		final = lhs % rhs;
		operator_stack.pop();
	} else if (op == '^') {
		final = 1;
		for (int i = 0; i < rhs; ++i) {
			final *= lhs;
		}
		operator_stack.pop();
	}
	operand_stack.push(final);
}


