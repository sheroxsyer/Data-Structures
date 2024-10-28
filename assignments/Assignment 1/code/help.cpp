
#include <iostream>

using namespace std;

// void start();
// void end();
// void next();
// void back();

class array
{
    public:
        int *p = nullptr;
        int *q = nullptr;
        int *r = nullptr;
        int index;
        int arr[6] = {1,2,3,4,5,6};

        array();
        void current();
        void start();
        void end();
        void next();
        void back();

}; 

array::array()
{
    this->p = arr;
    this->q = p;
    this->index = NULL;
}

void array:: current()
{
    cout<<"Your current position is: "<<*p<<endl;
}

void array::start()
{
    this->p = arr;
    this->index = NULL;
    cout<<"You are at the start of the array."<<endl;
    cout<<"And the value of p is: "<<*p<<endl;
}

void array::end()
{
    int length = sizeof(arr) / sizeof(int); 
    int *t;
    t = q + (length - 1);
    cout<<*t<<endl;

    // if (p == r)
    // {
    //     cout<<"You are already at the end of the array."<<endl;   
    // }

    // else
    // {
    //     for (int j = 1; j < length; j++)
    //     {
    //         if (index == length -1)
    //         {
    //             cout<<"You are already at the end of the array."<<endl;
    //             break;
    //         }
            
    //         else
    //         {
    //             p+=1;
    //             index++;
    //         }
    //     }
    //     // p-=1;
    //     r = p;
    //     cout<<"The value of p is: "<<*p<<endl;       
        
    // }


}

void array::next()
{
    int length = sizeof(arr) / sizeof(int);

    if (index == length - 1)
    {
        cout<<"You are already at the end of the array can't go further more."<<endl;   
    }
    else
    {
        cout<<"Your first position was: "<<*p<<endl;
        p +=1;
        index++;
        cout<<"And your next position is: "<<*p<<endl;
    }

}

void array::back()
{
    if (p == q)
    {
        cout<<"You are already at the start of the array can't go back anymore."<<endl;
    }
    else
    {
        cout<<"Your first position was: "<<*p<<endl;
        p -=1;
        index --;
        cout<<"And your previous position is: "<<*p<<endl<<endl;
    }
}

int main()
{
    int x;
    array a;
    do
    {
        cout<<"1.Current position."<<endl;
        cout<<"2.Start of the array."<<endl;
        cout<<"3.End of the array."<<endl;
        cout<<"4.Move next."<<endl;
        cout<<"5.Move back."<<endl;
        cout<<"0.Exit"<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;

        switch (x)
        {
        case 1:
            a.current();
            break;
        case 2:
            a.start();
            break;
        case 3:
            a.end();
            break;
        case 4:
            a.next();
            break;
        case 5:
            a.back();
            break;
        }

    } while (x != 0);
}