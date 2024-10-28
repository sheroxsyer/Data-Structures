# include<iostream>

using namespace std;

struct node
{
    int info;
    node *next;
    node *prev;
};

class list
{
    public:
        node *head,*temp , *temp1;

        void search();
        void del();
        void print();
        void add();


    list()
    {
        head = temp=temp1=NULL;
    }
};

void list :: print()
{
    temp = head;

    if(head == NULL)
    {
        cout<<"link list is empty"<<endl;
        return;     
    }

    while(temp != NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

void list :: add()
{
    int key;

    if (head == NULL)
    {
        head = new node;
        cout<<"please enter data"<<endl;
        cin>>head->info;
        head->next = NULL;
        head->prev = NULL;
        return;
    }

    temp=head;
    cout<<"Enter the key: ";
    cin>>key;

    while(temp != NULL)
    {
        if (temp->info == key)
        {
            temp1 = new node;
            cout<< "Enter the number: ";
            cin>>temp1->info;
            temp1->next = temp->next;
            temp->next = temp1;
            temp1->prev = temp;
            if(temp1->next != NULL)
            {
                temp1->next->prev = temp1;
            }
            else
            {
                return;
            }
        }
        temp = temp->next;
    }
    
}

void list :: del()
{
    int key;

    if (head == NULL)
    {
        cout<<"your list is empty"<<endl;
        return;
    }
    cout<<"enter the key"<<endl;
    cin>>key;
    temp = head;

    while(temp != NULL)
    {
        if (temp->info == key)
        {
            if(temp->prev != NULL)
            {
                temp1 = temp->prev;
                temp->prev->next = temp->next;
            }
            if(temp->next != NULL)
            {
                temp->next->prev=temp1->prev;
            }
            delete temp;
            temp = temp1;
        }
        temp = temp->next;
    }
    if (temp = head)
    {
        //deletion;
        //head will be updated;
    }
}

void list::search()
{
    int key;
    cout<<"Enter the number to be found: ";
    cin>>key;

    temp = head;

    while(temp != NULL)
    {
        if (temp->info == key)
        {
            cout<<"key found"<<endl;
            break;
        }
        else
        {
            cout<<"required data is not present plz add this data first and then try again"<<endl;
            break;
        }
        temp = temp->next;
    }
}
int main()
{
    list li;
    int x;
    do
    {
    
        cout<<"press 1 for addition"<<endl;
        cout<<"press 2 for deletion"<<endl;
        cout<<"press 3 for searching"<<endl;
        cout<<"press 4 for printing"<<endl;
        cout<<"press 0 for exit"<<endl;
        cout<<"which operation you want to perform"<<endl;
        cin>>x;

        switch(x)
        {
            case 1:
                li.add();
                break;
            case 2:
                li.del();
                break;
            case 3:
                li.search();
                break;
            case 4:
                li.print();
                break;
            default:
                break;
        }    

    } while (x != 0);
    
    return 0;   
}