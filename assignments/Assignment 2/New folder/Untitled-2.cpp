#include <iostream>

using namespace std;

struct node 
{
    int data;
    int key;
    node* next;
};

class linklist
{
    public:
    node *head , *temp , *temp1;
    
    linklist();
    void create();
    void insert();
    void printList();
    void deleteList();
    bool searchList();
    bool emptyList();


};

linklist::linklist()
{
    //node *head = nullptr;
    // node *temp = nullptr;
    // node *temp1 = nullptr;   
}

void linklist::create()
{
    int num;
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

    while (temp !=nullptr || temp1 !=nullptr )
    {
        temp1 = new node;
        temp1->data = num;
        temp1->next = temp->next;
        temp->next = temp1;
        temp1->next->next = nullptr;
    
        temp = temp->next;
    }
    return;
    
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
    
    while (temp !=nullptr || temp1 !=nullptr )
    {
        if (temp->data == pos)
        {
            temp1 = new node;
            temp1->data = num;
            temp1->next = temp->next;
            temp->next = temp1;
            temp1->next->next = nullptr;
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
    cout<<"your list is :"<<endl;
    cout<<endl;
}

// Delete a node
void linklist ::deleteList() 
{
    struct node** head; 
    int key;
  struct node *temp = *head, *prev;
  int num;
  int pos;

  cout<<"Enter the number to be entered: ";
    cin>>num;
    cout<<"Enter the position where you want to insert the number: ";
    cin>>pos;



  if (temp != NULL && temp->data == key) {
  *head = temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}

bool linklist :: searchList() 
{
    
struct node** head;
 int key;
  
  struct node* temp = *head;
    cout<<"enter the number you are searching"<<endl;
  while (temp != NULL) 
  {
  if (temp->data == key) return true;
  temp = temp->next;
  }
  return false;

}
bool linklist ::emptyList()
{
    if(head == 0)
    {
        cout<<"your list is empty"<<endl;
        return false;
    }
    else
    {
        cout<<"Your list is not empty"<<endl;
        return true;
    }
}

int main()
{
    linklist l;
    int x;

    do
    {
        cout<<"1.Create."<<endl;
        cout<<"2.Insert."<<endl;
        cout<<"3.Print."<<endl;
        cout<<"4.deleteList."<<endl;
        cout<<"5.searchList."<<endl;
        cout<<"6.emptyList."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.create();
            break;
        case 2:
            l.insert();
            break;
        case 3:
            l.printList();
            break;
        case 4:
            l.deleteList();
            break;
        case 5:
            l.searchList();
            break;
        case 6:
            l.emptyList();
            break;
        
        
        
        default:
            break;
        }
    } while (x != 0);
    
    return 0;
}
