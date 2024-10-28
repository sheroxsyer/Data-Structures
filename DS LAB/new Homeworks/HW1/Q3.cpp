#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    const int m = 5,n=5;
    int arr[m][n];
    ifstream iFile;
    iFile.open("a.txt");
    //this part is use for reading data from file which i store in the same file
    for(int i = 0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            iFile>>arr[i][j];
        }
    }

    iFile.close();

    //this part is used for printing data from file

    cout<<"your 2D arrray is :"<<endl;

    for (int i = 0; i < m; i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //this part is used for calculating sum of 2D array

    int array2[m];
    for (int i = 0; i < m; i++)
    {
        array2[i]=0;
        
    }
    cout<<"sum of 2D array is:"<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j< n; j++)
        {

            array2[i]=array2[i]+arr[i][j];
            
        }
        
    }
     for (int i = 0; i < m; i++)
    {
        cout<<array2[i]<<" ";
        
    }

    
    return 0;
    
}



