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
        BST();
        void insert(int , node*& );
        node *search(int , node*const& );
        void Post_ord(node *);
        void Pre_ord(node *);
        void InOrder(node *);
        int successor(int);
        node* minValueNode(node*);
        node* delete_bst(node* , int );
};

BST::BST()
{
    root = nullptr;
}

void BST::insert(int key , node *&temp)
{
    
    if (temp == nullptr) 
    {

        temp = new node;
        temp->info = key;
        temp->left = temp->right = nullptr;
    


        if (root == nullptr)
        {
            cout<<"your Converted AVL tree is:"<<endl;
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

void BST::Post_ord(node *temp)
{
    if(temp==NULL){
		cout<<"Tree is Empty "<<endl;
		return;
	}
	if(temp->left != NULL){
		Post_ord(temp->left);
	}
	if(temp->right != NULL){
		Post_ord(temp->right);
	}
	cout<<temp->info<<" ";
}

void BST::Pre_ord(node *temp)
{
	if(temp==NULL)
    {
		cout<<"Tree is Empty "<<endl;
		return;
	}
	cout<<temp->info<<" ";
	
	if(temp->left != NULL)
    {
		Post_ord(temp->left);
	}
	if(temp->right != NULL)
    {
		Post_ord(temp->right);
	}
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

int BST::successor(int key)
{
    node *temp = search(key , root);

    node *successor = nullptr;

    if (temp == nullptr)
    {
        return NULL;
    }
    
    if (temp->right != nullptr)
    {
        temp = temp->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->info;
    }
    else
    {
        node* temp2 = root;
        while (temp2 != temp)
        {
            if (temp2->info > temp->info)
            {
                successor = temp2;
                temp2 = temp2->left;
            }

            else
            {
                temp2 = temp2->right;
            }
        }
        return successor->info;
    }
}

node *BST:: minValueNode(struct node* temp)
{
    struct node* temp1 = temp;
 
    
    while (temp1 && temp1->left != NULL)
    {
        temp1 = temp1->left;
    }
    return temp1;
}

node *BST::delete_bst(struct node* temp, int key)
{
    if (temp == NULL)
        return temp;
    if (key < temp->info)
        temp->left = delete_bst(temp->left, key);
    else if (key > temp->info)
        temp->right = delete_bst(temp->right, key);
    else 
    {
        if (temp->left==NULL and temp->right==NULL)
            return NULL;
        else if (temp->left == NULL) 
        {
            struct node* temp1 = temp->right;
            delete temp;
            temp = nullptr;
            return temp1;
        }

        else if (temp->right == NULL) 
        {
            struct node* temp1 = temp->left;
            delete temp;
            temp = nullptr;
            return temp1;
        }
        struct node* temp1 = minValueNode(temp->right);
        temp->info = temp1->info;
        temp->right = delete_bst(temp->right, temp1->info);
    }
    return temp;
}

int main()
{
    BST b;
    cout<<"your Converted AVL tree is:"<<endl;

    

    b.insert(100 , b.root);
    b.insert(50 , b.root);
    b.insert(150 , b.root);
    b.insert(1 , b.root);
    b.insert(60 , b.root);
    b.insert(55 , b.root);
    b.insert(140 , b.root);
    b.insert(200 , b.root);

    b.InOrder(b.root);
    cout<<endl;
    cout<<b.successor(100);
    cout<<endl;
    cout<<b.successor(55);
    cout<<endl;

    b.delete_bst(b.root , 55);
    cout<<endl;
    b.InOrder(b.root);
    cout<<endl;
    
}
