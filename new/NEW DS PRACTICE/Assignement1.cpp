#include<iostream>
using namespace std;

class ADTArrayList
{
    private:
    int *current;
    int *q;
    int maxSize;
    int size;
    int count;
    int *array = new int[maxSize];

    public:
    ADTArrayList()
    {

        cout<<"Enter number of elements in array:"<<endl;
        cin>>maxSize;
        this->count=0;
        q = current;
        int i=0;  //for traversing the array

    };

    void get(int pos);
    void update(int pos,int val);
    void length();
    void back();
    void Next();
    void start(); 
    void end();
    void Remove_pos(int pos);
    void Remove_val(int val);
    void Add(int val);
    bool isFull();
    bool isEmpty();
    void print();

    ~ADTArrayList()
    {
        delete[] array;
    };
};


void ADTArrayList ::Add(int val)
{
    if(!isFull())

    {
        start();
        current=current+count;
        *current= val;
        count++;
    }    
    else{
        cout<<"array list if full"<<endl;
    }
}

bool ADTArrayList ::isFull(){
    if (count == size )
    
        //cout<<"Size full";
    
    return true;
    else 
    return false;
    
}

bool ADTArrayList ::isEmpty()
{
    if (count != size )
    // {
    //     cout<<"Size Empty";
    // }
    return true;
    else
    return false;

}

void ADTArrayList ::update(int pos,int val)
{
    start();
    if(!isFull())
    if ( pos <= count && pos > 0)
    {
        end();
        for(int i = count;i>=size;i--)
        {
            *(current +1) = *current;
            back();
        }
        Next();
        *current = val;
        count++;
    }
    else if(pos> count && pos <= maxSize)
    {
        start();
        current = current + pos -1;
        *current = val;
        count++;
    }
    else 
    {
        cout<<"invalid Position"<<endl;
    }
}
void ADTArrayList ::length()
{
    cout<<"The lenth of the array is :"<<count;
    return ;

}
void ADTArrayList ::back()
{
    current = current-1;
}
void ADTArrayList ::Next()
{
    current = current+1;

}
void ADTArrayList ::start()
{
    current = q;
    return ;
}
void ADTArrayList ::end()
{
    current= array+count-1;
    
}
void ADTArrayList ::Remove_val(int val)
{
    if(!isEmpty())
    {
        current=array;
        for(int i = 0;i<count;i++)
        {
            if(*current == val)
            {
            int *ptr = current;
            for(int j=0;j<count;j++)
            ptr++;
            *current=*ptr;
            current++;

            }
            count--;
        break;

        }
        current++;

    }
    
    else
    cout<<"Array is empty"<<endl;
} 
void ADTArrayList ::Remove_pos(int pos)
{
    if(!isEmpty())
    {
        if(pos < maxSize && pos >0)
        {
            start();
            current = current+pos-1;
            for(int i=0;i<count-pos;i++)
            {
                *current= *current+1;
                Next();

            }
            count--;
        }
        else
        cout<<"array is empty"<<endl;
    }
}
void ADTArrayList ::get(int )
{
    cout<<*current<<endl;
}

void ADTArrayList :: print()
{
    if(count >0)
    {
        start();
        for(int i =0;i<count;i++)
        {
            cout<<*current++<<endl;
        }
    }
        else
        {
            cout<<"Array is empty"<<endl;

        }    
}

int main()
{
    int x;
    ADTArrayList a;
    do
    {
        cout<<"1.start"<<endl;
        cout<<"2.end"<<endl;
        cout<<"3.next"<<endl;
        cout<<"4.add"<<endl;
        cout<<"5.remove by pos"<<endl;
        cout<<"6.remove by val"<<endl;
        cout<<"7.get"<<endl;
        cout<<"8.length"<<endl;
        cout<<"9.update"<<endl;
        cout<<"10.print"<<endl;
        cout<<"11.end"<<endl;

        cout<<"Enter your choice:"<<endl;
        cin>>x;
        switch (x)
        {
        case 1:
                a.start();
                cout<<"start"<<endl;
            break;
        case 2:
                a.end();
                cout<<"end"<<endl;
            break;
        case 3:
                a.Next();
                cout<<"next"<<endl;
            break;
        case 4:
                a.Add(1);
                cout<<"add"<<endl;
            break;            
        case 5:
                a.Remove_pos(2);
                cout<<"Remove_pos"<<endl;
            break;
        case 6:
                a.Remove_val(1);
                cout<<"Remove_val"<<endl;
                break;
                
        case 7:
                a.get(1);
                cout<<"get"<<endl;
            break;
        case 8:
                a.length();
                cout<<"length"<<endl;
            break;
        case 9:
                a.update(1,1);
                cout<<"update"<<endl;
            break;
        case 10:
                a.print();
                cout<<"print"<<endl;
            break;   
        default:
            break;
        }

    } 
    while (x!=0);
    
    return 0;
}