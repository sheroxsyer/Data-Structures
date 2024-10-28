#include <iostream>
#include <string>
//#include <stack>
using namespace std;

class stack
{
    
    
    public:
    int top;
    int*arr;
    int size;
        
    stack()
    {
        int s=5;
        
        size=s;
        arr = new int[size];
        top = -1;
        void push(int val);

    }



void push(int val)
{
    if (top == size-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        arr[top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        int val = arr[top];
        top--;
        return val;
    }
}

bool isEmpty()
{
    if(top < 0)
    {
        cout<<"Stack is empty"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

int top()
{
    int val;
    if (top == -1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        return val;
}
}
bool checkBrackets(string exp)
{
	char s;
	char ch;

	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			push(exp[i]);
			continue;
		}

		if (isEmpty())
			return false;

		switch (exp[i]) {
		case ')':
			
			ch =( top());
			pop();
			if (ch == '{' || ch == '[')
				return false;
			break;

		case '}':

			top();
			pop();
			if (ch == '(' || ch == '[')
				return false;
			break;

		case ']':

			
			top();
			pop();
			if (ch == '(' || ch == '{')
				return false;
			break;
		}
	}


	return (isEmpty());
}

void display()
{
    for( int i = top;top>=0;top--)
    {
        cout<<"Your stack is :"<<endl;
        cout<<top;
    }
}


};


int main()
{
	string exp = "{()))}[]))";

	
	if (checkBrackets(exp))
		cout << " Expression is Balanced";
	else
		cout << "Expression is not Balanced";
	return 0;
}
