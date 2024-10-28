#include<iostream>
#include<cstring>
using namespace std;
struct node
{
    char info[15];
};
class trial
{
    private:
    node obj1,*temp1,*temp2,*temp3;
    int I,length;
    char *p,*q;
    public:
        trial();
            ~trial();
            void startin();

};


void trial :: startin()
{
    cout<<"making use of new and delete is as follows:"<<endl;
    cout<<"............................................"<<endl;
    temp1=new node;
    temp2 =new node;
    cout<<"enter information about temp1"<<endl;
    cin>>temp1->info;
    cout<<"enter information about temp2"<<endl;
    cin>>temp2->info;
    temp3 =&obj1;
    cout<<"enter information about temp3"<<endl;
    cin>>temp3->info;
    cout<<"Showing information about temp1"<<endl;
    cin>>temp1->info;
    cout<<"Showing information about temp2"<<endl;
    cin>>temp2->info;
    cout<<"Showing information about temp3"<<endl;
    cin>>temp3->info;
    cout<<"............................................"<<endl;
    cout<<"Elements of array is as follows:"<<endl;
for(int i=0;i<length;i++)
{
    cout<<*p<<",";
    p=p+1;

}
    p=q;
    

}

int  main()
{
    trial Ink;
    Ink.startin();
    return 0;
}
void trial :: ~trial()
{
    delete temp1;
    delete temp2;
    delete temp3;
    delete[] p;
    
}