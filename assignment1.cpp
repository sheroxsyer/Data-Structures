#include<iostream>

 
using namespace std;
 
class stack
{
    private:
        int num[5];
        int top;
        int size;
        int temp;
        node *head;
        node *temp,*temp1;
    public:
        stack();    
        int push(int);
        int pop();
        int  isEmpty();
        int   isFull();
        void print();
};

struct node;
{
    int info;
    node *next;

}
stack::stack(){
    top=-1;
}
 
int  stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int stack::isFull(){
    if(top==(size-1))
        return 1;
    else
        return 0;
}
 
int  stack::push(int n){
    
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int  stack::pop(){
    
    int temp;
    
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void stack::print(){
    int i; 
    cout<<"stack is: ";
    for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
    cout<<endl;
}
 
int  main(){

    stack stk;
    int choice, n,temp;
     
    do
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Print stack."<<endl;
         
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"Your stack is full."<<endl;
                else
                    cout<<temp<<" It is inserted"<<endl;
            break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"Your stack is empty"<<endl;
                else
                    cout<<temp<<" is removed ."<<endl;
            break;
             
            case 3:
                stk.print();
                break;
             
            default:
                cout<<"Plz enter valid option."<<endl;
        }   
    }while(choice!=0);
 
     
    return 0;
     
}