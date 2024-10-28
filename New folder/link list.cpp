#include <iostream>

using namespace std;

struct node 
{
    int data;
    node* next;
};

class linklist
{
    public:
    node *head , *temp , *temp1;
    
    linklist();
    void insert();
    void delete_l();
    void printList();


};

linklist::linklist()
{
    node *head = nullptr;
    node *temp = nullptr;
    node *temp1 = nullptr;   
}

void linklist::insert()
{
    int num , pos;
    cout<<"Enter the number to be entered: ";
    cin>>num;
   

    if(head == nullptr)
    {
        head = new node;
        head->data = num;
        head->next = nullptr;
        return;
    }
    
    temp = head;

    cout<<"Enter the position where you want to insert the number: ";
    cin>>pos;

    while (temp !=nullptr)
    {
        if (temp->data == pos)
        {
            temp1 = new node;
            temp1->data = num;
            temp1->next = temp->next;
            temp->next = temp1;
        }
        temp = temp->next;
    }
    return;
}

void linklist::delete_l()
{
    int num;

    cout<<"Enter the number to be delete: ";
    cin>>num;

    if(head == nullptr)
    {
        cout<<"No node to be delete."<<endl;
        return;
    }

    temp = head;

    while (head->data == num)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    
    while (temp !=nullptr)
    {
        if (temp->next != NULL)
        {
            if (temp->next->data == num)
            {
                temp1 = temp->next;
                temp->next = temp->next->next;
                delete temp1;
                temp1 = nullptr;
            }
            
        }
        temp = temp->next;
    }
    return;

}


void linklist::printList()
{
    temp = head;

    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


int main()
{
    linklist l;
    int x;

    do
    {
        cout<<"1.Insert."<<endl;
        cout<<"2.Print."<<endl;
        cout<<"3.Delete."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.insert();
            break;
        case 2:
            l.printList();
            break;
        case 3:
            l.delete_l();
            break;
        default:
            break;
        }
    } while (x != 0);
    
    return 0;
}