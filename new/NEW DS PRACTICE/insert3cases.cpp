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
    node* head;
    int length;
public:
    SingleLinkedList() {
        head = NULL;
        length = 0;
    }
    // Insertion in Single Linklist
    void insertAtHead(int val) {
        node* t = new node(val);
        int pos;
        if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
        if (head == NULL) { // Head is Empty
            head = t;
            length++;
        }
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head == NULL)  // Head is Empty
                    head = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head;
                    head = t;
                }
                length++;
            }
        else {
            node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAtMiddle(int pos, int val) {
        node* t = new node(val);
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            
            else { // position can be in center or in last
                node* curr = head;
                node* pre = head;
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
    void insertAtEnd(int val)
    {
        node*t=new node(val);
        node *curr = head;
    
        int pos;
        if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            if(curr ==NULL )
            {
                t->next=curr;
                
            }
            length++;

    }
    // What about insert through Recursion.... ???
    // Printing
    void printing() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    
    int size() {
        return length;
    }
    node* getHead() {
        node* curr = head;
        return curr;
    }
};


int main() {
    SingleLinkedList obj;
    obj.insertAtHead(11);
    obj.insertAtMiddle(12,0);
    obj.insertAtMiddle(13,1);
    obj.insertAtMiddle(14,2);
    obj.insertAtMiddle(15,3);
    obj.insertAtMiddle(16,4);
    obj.insertAtMiddle(17,5);
    obj.insertAtMiddle(18,6);
    obj.insertAtEnd(300);
    obj.printing();

    return 0;
}