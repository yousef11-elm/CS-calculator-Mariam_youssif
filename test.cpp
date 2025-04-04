#include <iostream>
#include "calculator.h"
using namespace std;

int main(int argc, char* argv[])
{
    cout << "Add: " << add(3, 4) << '\n';
    cout << "Subtract: " << subtract(10, 5) << '\n';
    cout << "Multiply: " << multiply(6, 7) << '\n';
    cout << "Divide: " << divide(22.0, 7.0) << '\n';
    cout << "Factorial: " << factorial(5) << '\n';
    cout << "GCD: " << gcd(48, 18) << '\n';
    cout << "LCM: " << lcm(4, 5) << '\n';
    cout << "Random (1 to 10): " << randomInRange(1, 10) << '\n';
    string expr = "3 + 4 * (2 - 1) / 5";
    cout << "Expression Evaluation: " << expr << " = " << evaluateExpression(expr) << '\n';
    system("pause");
    return 0;
}
