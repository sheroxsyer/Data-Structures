#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
class array
{
private:
    int *current;
    int length;
    int * hdr;
    int maxSize;
public:
    array();
    ~array();
    int add(int pos, int val);
    int get(int pos);
    int remove(int pos);
    int next();
    int back();
    int start();
    int end();
    int update(int pos, int val);
    int length_();
};

 array::array()
{
    cout << "Enter the max size of the array :- "<< endl;
    cin >> maxSize; 
    current = new int [maxSize];
    length = 0;
    hdr = current;
}

array::~array()
{
    delete [] current;
}
int array::start()
{
    current = hdr;
    return 0;
}
int array::back()
{
    current = current - 1;
    return 0;
}
int array::next()
{
    current = current + 1;
    return 0;
}
int array::end()
{
    current = current + (length-1);
    return 0;
}
int array::get(int pos)
{
    start();
    int value = *(current+(pos-1));
    cout << "Value at position "<< pos << " is : "<<value<< endl;
    return 0;
}
int array::update(int val, int pos)
{
    start();
    *(current+(pos-1)) = val;
    return 0;
}
int array::add(int pos, int val)
{
    start();
    if (length==0)

    {
        *current = val;
    }
    else if (length==pos-1)
    {
        	*(current+pos-1) = val;
    }
    else
    {
        end();
        while (*(hdr+pos-1) != *(current))
        {
            *(current+1) = *(current);
            current = current-1;
        }
        *(current)=val;
                
    }
    length++;
    return 0;
}
int array::length_()
{
    cout << "Length of the array is : "<< length<<endl;
    return 0;
}
int array::remove(int pos)
{
    if (pos>length)
    {
        cout<< "Not possible:-\nTry another position"<<endl;
    }
    else
    {
        start();
        current = current+(pos-1);
        for (int i = 0; i < length-pos; i++)
        {
            *current = *(current+1);
        }
        length--;
        
    }
    return 0;
}
int main()
{
    array a;
    a.add(1,1);
    a.add(2,2);
    a.add(3,3);
    a.get(1);
    a.get(2);
    a.get(3);
    a.update(5, 3);
    a.length_();
    a.add(4, 6);
    a.add(2,9);
    a.get(3);
    a.get(2);
    a.get(4);
    a.length_();
    a.remove(4);
    a.get(4);
    a.length_();
    return 0;
}
