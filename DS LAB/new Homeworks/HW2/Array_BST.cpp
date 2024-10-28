#include<iostream>
using namespace std;
char Arr[100];
int arr_size=100;
int root(char key) {
if (Arr[0] != '\0')
	cout << "Tree already had root";
else
	Arr[0] = key;
return 0;
}

int LeftTree(char key, int index) {
if (Arr[index] == '\0')
	cout << "set child at "
	<< (index * 2) + 1
	<< " , no index found";
else
	Arr[(index * 2) + 1] = key;
return 0;
}

int RightTree(char key, int index) {
if (Arr[index] == '\0')
	cout << "set child at "
	<< (index * 2) + 2
	<< " , no index found";
else
	Arr[(index * 2) + 2] = key;
return 0;
}

bool Search(int ele)
{ 
    int curr = 0; 
    while(curr < arr_size) 
    {
         if(Arr[curr] == false)
          return false; 
        if(Arr[curr] == ele) 
            return true;
        else if(Arr[curr] < ele) 
            curr = 2*curr + 1;
         else
          curr = 2*curr + 2; 
    } 
        return false; 
  }
  void preorder(int index)
{
    
    if(index>0 && Arr[index]!='\0')
    {
        cout<<Arr[index]<<endl;
        preorder(LeftTree(index));
        preorder(RightTree(index)); 
    }
}

void postorder(int index)
{
    
    if(index>0 && Arr[index]!='\0')
    {
        postorder(LeftTree(index)); 
        postorder(RightTree(index)); 
        cout<<Arr[index]<<endl; 
    }
}

void inorder(int index)
{
    if(index>0 && Arr[index]!='\0')
    {
        inorder(LeftTree(index)); 
        cout<<Arr[index]<<endl; 
        inorder(RightTree(index)); 
    }
}
int FindHeight(int parent[], int n)

    
{
    
    int depth[n];
    for (int i = 0; i < n; i++)
        depth[i] = 0;
 
    
    for (int i = 0; i < n; i++)
        fillDepth(parent, i, depth);
}
void fillDepth(int parent[], int i, int depth[])
{
    
    if (depth[i])
        return;
 
    
    if (parent[i] == -1) {
        depth[i] = 1;
        return;
    }
 
    
    if (depth[parent[i]] == 0)
        fillDepth(parent, parent[i], depth);
 
    
    depth[i] = depth[parent[i]] + 1;
}
int LeafCount()  
{  
    int index;
    int lChildIndex = index*2+1;    //1
    int rChildIndex = (index*2)+2;  //2
    if( Arr[index] == '\0')      
        return 0;  
    if(Arr[lChildIndex] == NULL && Arr[rChildIndex] == NULL)  
        return 1;         
    else
        return LeafCount(Arr[lChildIndex])+  
            LeafCount(Arr[rChildIndex]);  
} 
int Display() {

cout << "\n";
for (int i = 0; i < 100; i++) {
	if (Arr[i] != '\0')
	cout << Arr[i];
	else
	cout << "-";
}
return 0;
}


int main() {
root(16);
LeftTree(3,0);
RightTree(8, 0);
LeftTree(9, 1);
RightTree(2, 1);
RightTree(7, 2);
Display();
return 0;
}
