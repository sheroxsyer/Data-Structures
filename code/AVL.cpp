#include <iostream>

using namespace std;

struct node
{
    int info;
    node *right , *left;
};

class BST
{
    public:
        node *root , *temp1 , *temp2;
        int balance_factor , count;

        BST();
        void insert(int , node*& );
        node *search(int , node*const& );
        void InOrder(node *);
        int height(node* );
        int bal_fac(node* );

        void right(node *&);    // left left
        void left(node *&);    // right right
};


BST::BST()
{
    root = nullptr;
    count = NULL;
}

int BST::height(node *temp)
{
    if (temp == nullptr)
    {
        return 0;
    }
    else
    {
        int left = height(temp->left);
        int right = height(temp->right);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
        
    }
    
}

int BST ::bal_fac(node *temp )
{
    int left = 0;
    int right = 0;

    if (temp != nullptr)
    {
       if (temp->left != nullptr)
       {
           left = height(temp->left);
       }
       
       if (temp->right != nullptr)
       {
           right = height(temp->right);
       }

       return left - right;
    }
    
}

void BST :: right(node *&temp) // left - left
{
    node *temp2 = temp->left;
    temp->left = temp2->right;
    temp2->right = temp;
    temp = temp2;
}

void BST :: left(node *&temp) // right - right
{
    node *temp2 = temp->right;
    temp->right = temp2->left;
    temp2->left = temp;
    temp = temp2;
}


void BST::insert(int key , node *&temp)
{
    if (temp == nullptr)      // check 1
    {
        temp = new node;
        temp->info = key;
        temp->left = temp->right = nullptr;

        if (root == nullptr)
        {
            cout<<"your AVL is:"<<endl;
            root = temp;
        }
        count++;
        // return;
    }

    if (temp->info == key)
    {
        cout<<"Duplicate."<<endl;
        return;
    }
    
    if (temp->info > key)
    {
        insert(key , temp->left);
        // return;
    }

    if (temp->info < key)
    {
        insert(key , temp->right);
    }

    if (count > 1)
    {
        balance_factor = bal_fac(temp);
        cout<<"bal: "<<balance_factor<<endl;
        
        if (balance_factor == 2)
        {
            if (key < temp->left->info)
            {
                right(temp);
                return;
            }
            else
            {
                left(temp->left);
                right(temp);
                return;
            }    
        }

        if (balance_factor == -2)
        {
            if (key > temp->right->info)
            {
                left(temp);
                return;
            }
            else
            {
                right(temp->right);
                left(temp);
                return;
            }    
        }

    }
    return;
    
}

void BST::InOrder(node *temp)
{
	if(temp == NULL)
    {
		cout<<"Tree is Empty "<<endl;
		return; 
	}
	if(temp->left !=NULL)
    {
		InOrder(temp->left);
	}
	cout<<temp->info<<" ";
	if(temp->right != NULL)
    {
		InOrder(temp->right);
	}
}

int main()
{
    BST b;

    b.insert(100 , b.root);
    b.insert(50 , b.root);
    b.insert(200 , b.root);
    // b.insert(150 , b.root);
    // b.insert(140 , b.root);
    // b.insert(300 , b.root);
    
    b.InOrder(b.root);   
}

