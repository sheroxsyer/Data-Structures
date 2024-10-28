#include <iostream>
using namespace std;

class node
{   
    public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }

};


class queue
{
    private:
        node * frontt, * rear;
        int lenght;
        int size;
    public:
        void enqueue(int);
        void dequeue();
        void print();
        bool isEmpty();
        bool isFull();
        queue();

};


queue ::queue()
{   
    cout << "Enter size for Queue: ";
    cin >> size;
    this->size = size;
    frontt = rear = NULL;
    lenght = 0;


}
void queue::enqueue(int val)
{   
    node *n = new node(val);
     
    if(frontt == NULL)
    {
       //rear->next = NULL;
       frontt = rear = n;
       lenght++;

    }
    else{

        rear->next = n;
        lenght++;

    }

}

void queue::dequeue()
{
    
    if(frontt==NULL)
    {
        cout<<"Nothing to delete: ";
        return;

    }


    node *temp = frontt;
    frontt = frontt->next;

    if(frontt == NULL)
    {
        rear = NULL;
    }

    delete temp;
    lenght--;

}

void queue::print()
{
    node *curr = frontt;
    while( curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }

}

bool queue::isEmpty()
{
    if(frontt == NULL && rear == NULL)
    {
        return true;
    }
    else 
        return false;
}

bool queue:: isFull()
{
    if(lenght == size)
        return true;
    else
        return false;



}





int main()
{
    queue q;

   
    q.enqueue(3);
   
    q.enqueue(6);

    q.print();
    cout << endl;

    q.dequeue();
    q.print();
}




