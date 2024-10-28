#include<iostream>

using namespace std;
int main()
{
    const int m = 6,n=6;
    int arr[m][n];
    
    
    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"Enter elements"<<"---->";
            cin>>arr[i][j];
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"You entered"<<"---->";
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //for matrix 2
    const int a = 6,b=6;
    int arr2[a][b];
    
    int result1,result2,result3;
    int sum;
    int n1,n2,n3;

    n1=arr[1][1];
    sum=arr[0][0]+arr[0][1]+arr[0][2]+arr[1][0]+arr[1][2]+arr[2][0]+arr[2][1]+arr[2][2];
    result1=sum/n1;
    sum =0;

    n2=arr[4][5];
    sum=arr[3][4]+arr[3][5]+arr[4][4]+arr[5][4]+arr[5][5];
    result2=sum/n2;
    sum =0;

    n3=arr[5][0];
    sum=arr[4][0]+arr[4][1]+arr[5][1];
    result3=sum/n3;
    
    cout<<" 1st result ="<<result1<<endl;
    cout<<" 2nd  result ="<<result2<<endl;
    cout<<" 3rd result ="<<result3<<endl;





    for(int i = 0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<"Enter elements"<<endl;
            cin>>arr[i][j];
        }
    }
    

    for (int i = 0; i < a; i++)
    {
        for(int j=0;j<b;j++)
        {
            cout<<"You entered"<<arr[i][j]<<endl;
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
    
}



