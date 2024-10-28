#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int expression(string exp) {
    // Create a stack for operands
    stack<int> s;
    // use loop for each character of the expression
    for(char c : exp) {
        //for push in stack
        if(isdigit(c)) {
            s.push(c - '0');
        } else {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch(c) {
                case '+':
                    s.push(op1 + op2);
                    break;
                case '-':
                    s.push(op1 - op2);
                    break;
                case '*':
                    s.push(op1 * op2);
                    break;
                case '/':
                    s.push(op1 / op2);
                    break;
                default:
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    getline(cin, exp);
    int result = expression(exp);
    cout << "Result: " << result << endl;
    return 0;
}



