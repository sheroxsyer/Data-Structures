#include <iostream>
#include <string>
#include <stack>
using namespace std;
 
int PostfixExpression(string exp)
{
    
    stack<int> stack;
 
    
    for (char ch: exp)
    {
        
        if (ch >= '0' && ch <= '9') {
            stack.push(ch - '0');
        }
        else {
            
            int a = stack.top();
            stack.pop();
 
            int b = stack.top();
            stack.pop();
 
            if (ch == '+') {
                stack.push(b + a);
            }
            else if (ch == '-') {
                stack.push(b - a);
            }
            else if (ch == '*') {
                stack.push(b * a);
            }
            else if (ch == '/') {
                stack.push(b / a);
            }
        }
    }
 
    return stack.top();
}
 
int main()
{
    cout<<"your expression is :"<<endl;
    string exp = "138*+";
 
    cout << PostfixExpression(exp);
 
    return 0;
}