// #include<iostream>
// using namespace std;
// class node
// {
//     public:
//     node*next;
//     int data;
//     node(int val)
//     {
//         data = val;
//         next = NULL; 
//     }
// };
// class SLL
// {
//     private:
//     node*head;
//     int length;
//     public:
//     SLL()
//     {
//         head = NULL;
//         length = 0;
//     }
//     void insert(int val)
//     {
//         node*t=new node(val);
//         if(head == NULL)
//         {
//             head = t;
//             length++;
//         }
//         else
//         {
//             node *curr =head;
//             while(curr->next!= NULL)
//             {
//             curr = curr->next;
//             }
//             curr->next=t;
//             length++;
//         }
//     }
//     void insertAt(int val,int pos)
//     {
//         if(pos < 1 || pos>length+1 )
//         {
//             cout<<"INvalid Position"<<endl;
//             return;
//         }

//         node*t=new node(val);
//         //to delete a node from head
//         if(pos == 1)
//         {
//         if(head ==NULL)
//         {
//             head = t;
//         }
//         else
//         {
//             t->next=head;
//             head = t;
//         }
//         length++;
//         }
        
//         else
//         {
//             node*curr=head;
//             node*temp =head;
//             for(int i=1;i<pos-1;i++)
//             {
//                 temp = curr;
//                 curr = curr->next;
//             }
//             temp->next=t;

//             if(curr !=NULL)
//             t->next=curr;
//             length++;
            

//         }
        
//     }
//     void removeAt(int pos)
//     {
//         node*curr=head;
//         if(head ==NULL)
//         {
//             cout<<"list is empty"<<endl;
//             return;
//         }
//         //deleting head
//         if(pos == 1)
//         {
//             head = curr->next;
//             delete curr;
//             length--;
//         }
//         else
//         {
//             node*temp1=NULL;
//             for(int i=0;i<pos-1;i++)
//             {
//                 temp1=curr;
//                 curr =curr->next;
//             }
//             temp1->next=curr->next;
//             curr->next=NULL;
//             delete curr;
//             length--;
//         }
//     }
//     int size()
//     {
//         return  length;
//     }
//     node*getHead()
//     {
//         node*curr = head;
//         return curr;
//     }
//     void print()
//     {
//         node*curr=head;
//         while(curr!= NULL)
//         {
//         cout<<curr->data<<endl;
        
        
//         curr = curr->next;
//     }
//     }
// };

// int main()
// {
//     SLL a;
//     a.insert(1);
//     a.insert(2);
//     a.insert(3);
//     a.print();
//     a.insertAt(4,2);
//     a.print();
//     a.removeAt(1);
//     a.print();

//     return 0;


// }


#include<iostream>
using namespace std;
class node {
public:
    node* next;
    int data;
    node(int val) {
        data = val;
        next = NULL;
    }
};
class SingleLinkedList
{
private:
    node* head1;
    node* head2;
    int length;
public:
    SingleLinkedList() {
        head1 = NULL;
        head2 = NULL;
        length = 0;
    }
    // Insertion in Single Linklist
    void insert_in_1stLL(int val) {
        node* t = new node(val);
        if (head1 == NULL) { // Head is Empty
            head1 = t;
            length++;
        }
        else {
            node* curr = head1;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt_1st_LL(int pos, int val) {
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head1 == NULL)  // Head is Empty
                    head1 = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head1;
                    head1 = t;
                }
                length++;
            }
            else { // position can be in center or in last
                node* curr = head1;
                node* pre = head1;
                for (int i = 1; i < pos-1; i++) {
                    pre = curr;
                    curr = curr->next;
                }
                pre->next = t;
                if (curr != NULL) // If its not a Last node
                    t->next = curr;
                length++;
            }
    }
    // What about insert through Recursion.... ???
    // Printing
    void printing_1st_LL() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head1;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    // Removing Node from List
    // What about removing node through Recursion.... ???
    void removeAt_1st_LL(int pos) {
        node* curr = head1;
        if (head1 == NULL) {
            cout << "LIST is empty " << endl;
            return;
        }
        if (pos == 1) {  // for deleting head
            head1 = curr->next;
            delete curr;
            length--;
        }
        else {   // for deleting any other node
            node* temp = NULL;
            for (int i = 0; i < pos - 1; i++) {
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = NULL;
            delete curr;
            length--;
        }
    }
    int size() {
        return length;
    }
    node* getHead_1st_LL() {
        node* curr = head1;
        return curr;
    }
    //implementation of 2nd linked list
    void insert_in_2nd_LL(int val) {
        node* t = new node(val);
        if (head2 == NULL) { // Head is Empty
            head2 = t;
            length++;
        }
        else {
            node* curr = head2;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt_2nd_LL(int pos, int val) {
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head2 == NULL)  // Head is Empty
                    head2 = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head2;
                    head2 = t;
                }
                length++;
            }
            else { // position can be in center or in last
                node* curr = head2;
                node* pre = head2;
                for (int i = 1; i < pos-1; i++) {
                    pre = curr;
                    curr = curr->next;
                }
                pre->next = t;
                if (curr != NULL) // If its not a Last node
                    t->next = curr;
                length++;
            }
    }
    // What about insert through Recursion.... ???
    // Printing
    void printing_2nd_LL() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head2;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    // Removing Node from List
    // What about removing node through Recursion.... ???
    void removeAt_2nd_LL(int pos) {
        node* curr = head2;
        if (head2 == NULL) {
            cout << "LIST is empty " << endl;
            return;
        }
        if (pos == 1) {  // for deleting head
            head2 = curr->next;
            delete curr;
            length--;
        }
        else {   // for deleting any other node
            node* temp = NULL;
            for (int i = 0; i < pos - 1; i++) {
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = NULL;
            delete curr;
            length--;
        }
    }
    
    node* getHead_2nd_LL() {
        node* curr = head2;
        return curr;
    }
    node* merge(node * head1,node * head2)
    {
        node*p1=head1;
        node*p2=head2;
        node*dummyNode=new node(-1);
        node*p3 = dummyNode;

        while(p1 != NULL && p2 != NULL)
        {
            if(p1->data  < p2->data)
            {
            p3->next=p1;
            p1=p1->next;
            }
            else
            {
                p3->next=p2;
                p2=p2->next;
            }
            p3=p3->next;
        }

        while(p1 != NULL)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        while(p2 != NULL)
        {
            p3->next=p2;
            p2 = p2->next;
            p3=p3->next;
        }
        cout<<dummyNode->data;
        return dummyNode->next;



    }

};


int main() {
    node*head1=NULL; 
    node*head2 = NULL;

    SingleLinkedList obj;
    obj.insert_in_1stLL(11);
    obj.insert_in_1stLL(12);
    obj.insert_in_1stLL(13);
    obj.printing_1st_LL();
    obj.insert_in_2nd_LL(14);
    obj.insert_in_2nd_LL(15);
    obj.insert_in_2nd_LL(16);
    obj.insert_in_2nd_LL(17);
    obj.insert_in_2nd_LL(18);
    obj.printing_2nd_LL();
    obj.merge(head1,head2);
    

    return 0;
}