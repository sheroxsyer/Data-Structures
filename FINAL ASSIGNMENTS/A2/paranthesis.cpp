#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool parenthesis(string s) {
    stack<char> string;
    for(char c : s) 
    {
        if(c == '(' || c == '{' || c == '[') 
        {
            string.push(c);
        } 
        else if(c == ')' || c == '}' || c == ']') 
        {
            if(string.empty()) 
            {
                return false;
            } 
            else if((c == ')' && string.top() == '(') || (c == '}' && string.top() == '{') || (c == ']' && string.top() == '[')) 
            {
                string.pop();
            } 
            else 
            {
                return false;
            }
        }
    }
    return string.empty();
}

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    if(parenthesis(s)) {
        cout << "Parenthesis matched ." << endl;
    } else {
        cout << "Parenthesis left in stack." << endl;
    }
    return 0;
}
