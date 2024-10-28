#include<iostream>
using namespace std;
int main()
{
    int x=5;
    int*ptr=NULL;
    ptr=&x;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<*&ptr<<endl;
    cout<<&x<<endl;
    x=6;
    cout<<x<<endl;
    cout<<&x<<endl;
}