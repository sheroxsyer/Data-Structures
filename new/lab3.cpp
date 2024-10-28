#include<iostream>
#include<conio.h>
using namespace std;

class Arraylist
{
    private:
    int *arr;
    int size;
    int length;
    int *curr;


    public:
    Arraylist(int s)
    {
        size=s;
        arr = new int[size];
        length = 0
    };

    ~Arraylist()
    {
        delete[]arr;
    }

    void start();
    void printlist();
    int searchElement(int x);
    void insertElement (int X);
    void insertElementAt (int X,int pos);
    bool deleteElement (int X);
    bool isFull();
    bool isEmpty ( );
};
    void Arraylist :: start()
    {
        cout<<" YOu are at the location "<< *curr<<endl;
    }

    void Arraylist :: printlist()
    {
        int*ptr = arr;
        for (int i =0;i<size;i++)
        {
            cout<<*ptr++<<endl;

        }
    }
    
    int Arraylist :: searchElement(int x)
    {
        //check for element exist
        
        bool found = false;
        start();
        for(int i =1;i<length;i++)
        {
            if(*curr == x)
            {
                found = true;
                return found;
            }
                curr++;
        }
        return found;
    }
void Arraylist :: insertElement (int X)
{
    cout<<"Enter the element :"<<endl;
    cin>>X;

    for (int i=1;i<size;i++)
    {
        *(curr +1)=*curr;
        *(curr + 1) = X;
        length ++;
    }

    

}    
void Arraylist :: insertElementAt (int X, int pos)
{
    cout<<"Enter element:"<<X<<endl;
    cout<<"Enter position:"<<pos<<endl;

    //tail();
    for(int i=length;i>pos;i--)
    {
        *(curr +1)=*curr;
        //back();
        *(curr + 1) = X;
        length ++;
    }
}

bool Arraylist :: deleteElement (int X)
{
     cout<<"Enter value:"<<X<<endl;
     start();
     if(*curr=X)
     {
         delete *curr;
     }

}

bool isFull ( )
{
    int *curr;
    int length;
    if(*curr =length - 1)
    {
        cout<<"List is full"<<endl;
        return true;
    }
    return false;

}
bool isEmpty ( )
{
    int length;
    int *curr;
    if(*curr !=length - 1)
    {
        cout<<"List is empty"<<endl;
        return true;
    }
    return false;
}


int main()
{
    Arraylist a;
    int x;
    do
    {
    

        cout<<"Enter your choice: ";
        cin>>x;

        switch (x)
        {
        case 1:
            a.deleteElement();
            break;
        case 2:
            a.start();
            break;
        case 3:
            a.insertElement();
            break;
        case 4:
            a.insertElementAt();
            break;
        case 5:
            a.isEmpty();
            break;

        case 6:
            a.isFull();
            break;
        case 7:
            a.printlist();
            break;
        case 8:
            a.searchElement();
            break;
        }

    } while (x != 0);


}
