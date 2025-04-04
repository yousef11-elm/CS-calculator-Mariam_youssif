#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>
using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
double factorial(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int randomInRange(int min, int max);
int precedence(char op);
int applyOperator(int a, int b, char op);
int evaluateExpression(const std::string& expression);
double power(double base, int exponent);


#endif 