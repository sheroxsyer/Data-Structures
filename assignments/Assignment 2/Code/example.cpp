#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int *intptr = new int;
    char *namestr = new char[8];
    *intptr=357;
    strcpy(namestr,"datastructure");
    return 0;
}