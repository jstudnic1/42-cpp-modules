#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::run(const std::string &expression) {
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] == ' ') continue;
		if (expression[i] >= '0' && expression[i] <= '9') {
			_stack.push(expression[i] - '0');
		}
		else if (expression[i] == '+') {
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands.\n";
				return;
			}
			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();
			long res = (long)lhs + rhs;
			if (res > INT_MAX || res < INT_MIN) {
				std::cerr << "Error: overflow.\n";
				return;
			}
			_stack.push(static_cast<int>(res));
		}
		else if (expression[i] == '-') {
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands.\n";
				return;
			}
			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();
			long res = (long)lhs - rhs;
			if (res > INT_MAX || res < INT_MIN) {
				std::cerr << "Error: overflow.\n";
				return;
			}
			_stack.push(static_cast<int>(res));
		}
		else if (expression[i] == '*') {
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands.\n";
				return;
			}
			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();
			long res = (long)lhs * rhs;
			if (res > INT_MAX || res < INT_MIN) {
				std::cerr << "Error: overflow.\n";
				return;
			}
			_stack.push(static_cast<int>(res));
		}
		else if (expression[i] == '/') {
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands.\n";
				return;
			}
			int rhs = _stack.top();
			_stack.pop();
			int lhs = _stack.top();
			_stack.pop();
			if (rhs == 0) {
				std::cerr << "Error: division by zero.\n";
				return;
			}
			long res = (long)lhs / rhs;
            if (res > INT_MAX || res < INT_MIN) {
                std::cerr << "Error: overflow.\n";
                return;
            }
			_stack.push(static_cast<int>(res));
		}
		else {
			std::cerr << "Error: invalid operator.\n";
			return;
		}
	}
	if (_stack.size() != 1) {
		std::cerr << "Error: too many operands.\n";
		return;
	}
	std::cout << _stack.top() << std::endl;
}
