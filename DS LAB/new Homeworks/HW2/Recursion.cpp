


/*

First of all recursion to get how many combination will be genrated and then we use recursion function --arr() which will give us arr which has all the value and combination 
and we passed in binary search tree class array Then we use heap the concept array to make a binary tree 
and then used level by  level traversal to print the series of cobbination.
*/ 

#include <iostream>
using namespace std;

int countWays(int n)
{
    int res[n + 1];
    res[0] = 1;
    res[1] = 1;
    res[2] = 2;
    for (int i = 3; i <= n; i++)
        res[i] = res[i - 1] + res[i - 2] + res[i - 3];

    return res[n];
}




// This code is contributed by shubhamsingh10

class node{
	public:
	int data;
	node* left, *right ,*next;
    
    int i=0;
	
};
class BinarySearchTree{
		public:

	node obj3;
	node* root;
	    int arr[20];

    node* Insert( node* root, int val);
	void    Insert(int val){
       
       Insert(this->root,  val);}


	int fun(int n,int i,int p )
	{
    	if(i!=(p+1))
    {
        arr[i]=n;
    }
    if(n==1)
    {
        return 1;
    }else if(n<0)
    {
        return 0;
    }else 
    {
        return fun(n-1,i=i+1,p),fun(n-(n-1),i=i+1,p),fun(n-(n-1),i=i+1,p);

    }
	}

	node* BinarySearchTree::Insert(node* r, int val )
	{
 if (r==NULL)
    {
        node* t= new node;
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
	}

	void print(node*temp,int level,int n)
	{
	if(n=level)
	{
		cout<<temp->next;
		return;
	}
	if(temp->left != NULL)
	{
		print(temp->left,level,n+1);
	}
	if(temp->right != NULL)
	{
		print(temp->right,level,n+1);
	}
	}


	void levelTraversal(node*temp,int level)
	{
	for(int i=0;i<level;i++)
	{
		print(temp,i,0);
		cout<<endl;
	}
	}

	void array_01()
	{
    
    for(int j=0; j>10; j++ ){
        cout<<arr[j];
    }
	}
};


int main() 
{
    // Write C++ code here
	BinarySearchTree obj5;
	node obj9;
    int s=0;
    s=countWays(4);
   obj5 .fun(4,0,s);
    obj5.array_01();
	for(int i=0; i<s; i++ )
	{

     
	  obj5.Insert(obj5.root,obj5.arr[i]);
    
	}


   
    

    return 0;
}