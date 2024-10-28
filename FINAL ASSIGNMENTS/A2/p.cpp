#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(string expression) {
    stack<int> stack;

    // Iterate through each character of the expression
    for (char& c : expression) {
        // If the character is an operand, push it onto the stack
        if (isdigit(c)) {
            stack.push(c - '0'); // Convert the character to an integer and push onto the stack
        }
        // If the character is an operator, pop the last two operands off the stack, perform the operation, and push the result back onto the stack
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            switch(c) {
                case '+': stack.push(operand1 + operand2); break;
                case '-': stack.push(operand1 - operand2); break;
                case '*': stack.push(operand1 * operand2); break;
                case '/': stack.push(operand1 / operand2); break;
            }
        }
    }

    // After iterating through all characters in the expression, the result will be the last item on the stack
    return stack.top();
}

int main() {
    // Example usage
    string postfixExpression = "23+5*";
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
