#include "calculator.h"
#include <ctime>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

int add(int a, int b) {
    return a + b;
}
int subtract(int a, int b) {
    return a - b;
}
int multiply(int a, int b) {
    return a * b;
}
double divide(double a, double b) {
    if (b == 0) {
        cout << "error cannot divide by zero, try again" << endl;
        return 0;
    }
    return a / b;
}
double factorial(int n) {
    if (n < 0) {
        cout << "error factorial of a negative number." << endl;
        return 0;
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) result *= i;
    return result;
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / gcd(a, b);
}
int randomInRange(int min, int max) {
    if (min > max) {
        cout << "error invalid range." << endl;
        return 0;
    }
    srand(static_cast<unsigned>(time(nullptr))); // used this with dr howaida 
    return min + rand() % ((max - min) + 1);
}
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int applyOperator(int a, int b, char op) {
    if (op == '+') return add(a, b);
    if (op == '-') return subtract(a, b);
    if (op == '*') return multiply(a, b);
    if (op == '/') return divide(a, b);
    return 0;
}
int parseNumber(const string& expr, int& i) {
    int num = 0;
    // loop through the characters of the number 
    while (i < expr.length() && expr[i] >= '0' && expr[i] <= '9') {
        num = num * 10 + (expr[i] - '0'); // construct the number
        i++;
    }
    return num;
}

int evaluateExpression(const string& expr) {
    stack<int> values;
    stack<char> ops;

    int i = 0;
    while (i < expr.length()) {
        if (expr[i] == ' ') {
            i++; // skip spaces
            continue;
        }

        if (expr[i] >= '0' && expr[i] <= '9') {
            // if its a number parse it
            int val = parseNumber(expr, i);
            values.push(val);
        }
        else if (expr[i] == '(') {
            // if it's an opening parenthesis push it onto the ops stack
            ops.push(expr[i]);
            i++;
        }
        else if (expr[i] == ')') {
            // if its a closing parenthesis resolve the expression inside
            while (!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.pop(); // pop the opening '('
            i++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            // process the operator based on its precedence
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperator(a, b, op));
            }
            ops.push(expr[i]);
            i++;
        }
    }

    // do any remaining
    while (!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperator(a, b, op));
    }

    return values.top();
}
double power(double base, int exponent) {
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    double result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

