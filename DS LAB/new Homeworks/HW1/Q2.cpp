#include<iostream>
using namespace std;
void Table(int *p,int *ptr)

    {
        for(int i=1; i<=*ptr; i++)
    {
        cout<<*p<<"*"<<i<<"="<<(*p) *i<<endl;
    }
        
    }

int main()
{
    int n;
    int lim;
    int *p;
    int *ptr;
    cout<<"Enter table number: "<<endl;
    cin>>n;
    cout<<"Enter table  limit"<<endl;
    cin>>lim;
    p=&n;
    ptr =& lim;
    // cout<<*lim;
    // int result = *n * i;
    Table(p,ptr);
}