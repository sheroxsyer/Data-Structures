#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node *next;
};
class link_list
{
    
node *head= new node();
node *curr= new node();
int length=0;

link_list();
    void GoToHead();
    void insertNodeAtEnd(int val);
    void AddNodeBeforeHead( int val);
    void InsertAfterSpecificKey(int val, int key );
    void InsertBeforeSpecificKey(int val, int key );
    void printLinklist();
    void DeleteNodeUsingKey(int key);
    void DeleteNodeUsingPos(int pos);
    void InsertNodeUsingKey(int val, int key, bool isBefore);
    void InsertNodeUsingPos(int val, int pos, bool isBefore);
    bool SearchList(int val);
    bool EmptyList();
    void next();
    void swapNodes(node** head,int x, int y);
};

link_list::link_list()
{
    //node *head = nullptr;
    // node *temp = nullptr;
    // node *temp1 = nullptr;   
}

void link_list :: GoToHead() { // set curr pointer to head node;
	curr= head;
}

void link_list :: insertNodeAtEnd(int val) { // This function will insert new node at the end.
	GoToHead();
	node *t= new node();
	while(curr->next!=NULL)
		curr= curr->next;
	t->data= val;
	t->next= NULL;
	curr->next= t;
	length++;
}
void link_list :: AddNodeBeforeHead( int val) { // This function will insert new node as a head.
	GoToHead();
	node *t= new node();
	t->data= val;
	t->next= curr;
	head= t;
	length++;
}
void link_list :: InsertAfterSpecificKey(int val, int key ) {
	node *t= new node();
	GoToHead();
	while (curr!=NULL) {
		if (curr->data==key) {
			t->data= val;
			t->next= NULL;
			t->next= curr->next;
			curr->next= t;
			length++;
			break;
		}
		curr= curr->next;
	}
}
void link_list :: InsertBeforeSpecificKey(int val, int key ) {
	node *ptr=NULL;
	GoToHead();
	while (curr!=NULL) {
		if (curr->data==key) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr;
			ptr->next= t;
			length++;
			break;
		}
		ptr= curr;
		curr= curr->next;
	}
}
void link_list :: printLinklist() {
	GoToHead();
	while(curr!=NULL) {
		cout<<curr->data<<"\t";
		curr= curr->next;
	}
}

void link_list :: DeleteNodeUsingKey(int key) {
	GoToHead();
	node *prenode= new node();
	if(curr->data== key) {
		head= curr->next;
		delete curr;
		length--;
		return;
	} else
		while(curr!=NULL) {
			if(curr->data==key) {
				prenode->next= curr->next;
				delete curr;
				length--;
				break;
			}
			prenode= curr;
			curr=curr->next;
		}

}
void link_list :: DeleteNodeUsingPos(int pos) {
	GoToHead();
	node *prenode= new node();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 ) { // if we want to delet head node
		prenode= curr;
		head= curr->next;
		delete prenode;
		length--;
	} else {
		for (int x=1; x<pos; x++) {
			prenode= curr;
			curr= curr->next;
		}
		prenode->next= curr->next;
		delete curr;
		length--;

	}
}

void link_list :: InsertNodeUsingKey(int val, int key, bool isBefore) {
	if (isBefore)
		InsertBeforeSpecificKey( val, key);
	else
		InsertAfterSpecificKey( val, key);

}
void link_list :: InsertNodeUsingPos(int val, int pos, bool isBefore) {
	GoToHead();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 && isBefore ) { // if we want to insert before head
		AddNodeBeforeHead(val);
	} else {
		node *prenode= new node();
		for (int x=1; x<pos; x++) {
			prenode= curr;
			curr= curr->next;
		}
		if (isBefore) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr;
			prenode->next= t;

		} else {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr->next;
			curr->next= t;
		}
	}

}
void next()
    {
        node *curr= new node();
        curr = curr + 1;
    }
bool link_list :: SearchList(int val)
{
    node *curr= new node();
    bool found = false;
    GoToHead();
    for(int i=1;i<=length;i++)
    {
        if(curr->data == val)
        {
            found = true;
            return found;
        }
        next();
    }
    return found;
}

bool link_list :: EmptyList()
{
    if(head == 0)
    {
        cout<<"your list is empty"<<endl;
        return false;
    }
    else
    {
        cout<<"Your list is not empty"<<endl;
        return true;
    }
}
void swapNodes(node** head,int x, int y)
{
    if (x == y)

        return;
    node *prevX = NULL, *currX = *head;
while (currX && currX->data != x) {

        prevX = currX;

        currX = currX->next;

    }

    node *prevY = NULL, *currY = *head;

    while (currY && currY->data != y) {

        prevY = currY;

        currY = currY->next;

    }

    if (currX == NULL || currY == NULL)

        return;

    if (prevX != NULL)

        prevX->next = currY;

    else 

        *head= currY;

    if (prevY != NULL)

        prevY->next = currX;

    else 

        *head = currX;

    node* temp = currY->next;

    currY->next = currX->next;

    currX->next = temp;
}
int main () {
	//head->data= 1;
	//head->next=NULL;

    link_list l();
    int x;

    do
    {
        cout<<"1.GoToHead."<<endl;
        cout<<"2.insertNodeAtEnd."<<endl;
        cout<<"3.AddNodeBeforeHead."<<endl;
        cout<<"4.InsertAfterSpecificKey."<<endl;
        cout<<"5.InsertBeforeSpecificKey."<<endl;
        cout<<"6.printLinklist."<<endl;
        cout<<"7.DeleteNodeUsingKey."<<endl;
        cout<<"8.DeleteNodeUsingPos."<<endl;
        cout<<"9.InsertNodeUsingKey."<<endl;
        cout<<"10.InsertNodeUsingPos."<<endl;
        cout<<"0.Exit."<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>x;
        switch (x)
        {
        case 1:
            l.GoToHead();
            break;
        case 2:
            l.insertNodeAtEnd( val);
            break;
        case 3:
            l.AddNodeBeforeHead(  val);
            break;
        case 4:
            l.InsertAfterSpecificKey( val,  key );
            break;
        case 5:
            l.InsertBeforeSpecificKey( val,  key );
            break;
        case 6:
            l.printLinklist();
            break;
        case 7:
            l.DeleteNodeUsingKey( key);
            break;
        case 8:
            l.DeleteNodeUsingPos( pos);
            break;
        case 9:
            l.InsertNodeUsingKey( val,  key,  isBefore);
            break;
        case 10:
            l.InsertNodeUsingPos( val,  pos,  isBefore);
            break;
        
        default:
            break;
        }
    } while (x != 0);

	// insertNodeAtEnd(2);
	// insertNodeAtEnd(3);
	// insertNodeAtEnd(4);
	// printLinklist();
	// cout<<endl;

	// InsertAfterSpecificKey(99, 2);
	// printLinklist();
	// cout<<endl;

	// DeleteNodeUsingKey(99);
	// printLinklist();
	// cout<<endl;

	// InsertBeforeSpecificKey(99, 2);
	// printLinklist();
	// cout<<endl;

	// InsertNodeUsingPos(88,1,true);
	// printLinklist();
	// cout<<endl;

	// DeleteNodeUsingPos(1);
	// DeleteNodeUsingPos(2);

	// printLinklist();
	// cout<<endl;
	return 0;
}
