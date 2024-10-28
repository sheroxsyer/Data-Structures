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
        int balance_factor;
        BST();
        void insert(int , node*& );
        node *search(int , node*const& );
        void InOrder(node *);
        int height(node*& );
        int bal_fac(node* );
};

BST::BST()
{
    root = nullptr;
}

int BST::height(node *&temp)
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


void BST::insert(int key , node *&temp)
{
    if (temp == nullptr)      // check 1
    {
        temp = new node;
        temp->info = key;
        temp->left = temp->right = nullptr;

        if (root == nullptr)
        {
            root = temp;
        }
        
        return;
    }

    if (temp->info == key)
    {
        cout<<"Duplicate."<<endl;
        return;
    }
    
    if (temp->info > key)
    {
        insert(key , temp->left);
        return;
    }

    if (temp->info < key)
    {
        insert(key , temp->right);
    }

    balance_factor = bal_fac(temp);

    if (balance_factor == 0)
    {
        return;
    }

    else if (balance_factor == -1)
    {
        return;
    }

    else if (balance_factor == 1)
    {
        return;
    }

    else
    {
        if (key < temp->info)
        {
            if (key < temp->left->info)
            {
                temp->right = temp->right->left;
                temp->right->left = temp->right->left->right;
            }
            else
            {
                // double rotation
            }
            
        }
        else
        {
            if (key > temp->right->info)
            {
                temp->left = temp->left->right;
                temp->left->right = temp->left->right->left;
            }
            else
            {
                // double rotation
            }
            
            
        }
        
    }
    
}

node *BST::search(int key , node * const &temp)
{
    if (root == nullptr)
    {
        cout<<"Tree is empty."<<endl;
        return NULL;
    }
    
    if (key == temp->info)
    {
        return temp;
    }
    
    if ( (temp->left != NULL) && (key < temp->info) )
    {
        return search(key , temp->left );
    }
    
    if ( (temp->right != NULL) && (key > temp->info) )
    {
        return search(key , temp->right );
    }
    cout<<"Search not found."<<endl;
    return NULL;
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
    // int x, num;

    // do
    // {
    //     cout<<"1.Insert"<<endl;
    //     cout<<"2.Search"<<endl;
    //     cout<<"3.Inorder"<<endl;
    //     cout<<"0.Exit"<<endl<<endl;

    //     cout<<"Enter your choice: ";
    //     cin>>x;
    //     switch (x)
    //     {
    //     case 1:
    //         cout<<"Enter the number: ";
    //         cin>>num;
    //         b.insert(num , b.root);
    //         break;
    //     case 2:
    //         cout<<"Enter the number for search: ";
    //         cin>>num;
    //         b.search(num , b.root);
    //         break;
    //     case 3:
    //         b.InOrder(b.root);
    //         cout<<endl;
    //         break;
    //     default:
    //         break;
    //     }
    // } while (x != 0);

    b.insert(50 , b.root);
    b.insert(100 , b.root);
    b.insert(70 , b.root);
    b.insert(110 , b.root);

    b.InOrder(b.root);

    b.insert(80 , b.root);
    
}

