#include<iostream>
using namespace std;

class list
{
    private:
    int *arr;
    int size;
    int length;
    int *curr;

    public:
    list(int s)
    {
        size=s;
        arr = new int[size];
        length = 0
    };

    ~list()
    {
        delete[]arr;
    }
    

    

};

