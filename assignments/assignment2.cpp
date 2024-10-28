#include <iostream>
using namespace std;

class Node
{
    public:
    Node * next;
    int data;
    Node(int value){
        data = value;
        next = NULL;
    }       
};
class List
{
    Node *head;
    int length;
public:
    
    List(){
        Node * p, *curr;
        head = curr = p = NULL;
        length = 0;
    }
    void insertion(int p , int value){
    Node *n = new Node(value);
    Node * curr = head;
    if (length == 0 && p == 1)
    {
        head = n;
    }
    else if (length > 0 && p == 1)
    {
        n->next = head;
        head = n;
    }
    else if (p > length+1)
    {
        cout<<"Wrong position"<<'\n';
    }
    else
    {
        for (int i = 1; i < (p - 1); i++)
        {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }
    length++;
}
    void deletion(int p){
    Node * curr = head;
    if (length == 0)
    {
        cout << "No Element Present in List" << '\n';
    }
    else if (p == 1)
    {
        head = head->next;
        delete curr;
    }
    else
    {
        Node *pre = nullptr;
        for (int i = 1; i < p; i++)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
    }
    length--;   
}
    bool search(int value){
    bool exist = false;
    Node * curr = head;
    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            exist = true;
            cout << exist << '\n';
        }
        curr = curr->next;
    }
    cout << exist<<'\n';
}
    void print(){
        Node * curr;
        curr = head ;
        if (head ==NULL)
        {
            cout<<"Linked list is empty./n";
            return;
        }
        
        for (int i = 0; i <= length; i++)
    {
        cout<< curr->data << '\n';
        curr = curr->next;
    }
}
bool emptiness(){
    bool exist = false;
        if (head== NULL)
        {
            exist = true;
            return exist;
        }
    return exist;
}
~List(){
    delete head;
}
};

int main(){
    List list1;
        
        return 0;
}