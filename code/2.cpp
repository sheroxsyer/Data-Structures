#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LL {
    public:
        Node* temp, *head, *temp2;
        int len;

        LL() {
            temp = head = temp2 = NULL;
            len = 0;
        }

        bool isEmpty() {
            if (head == NULL) {
                return true;
            }

            else {
                return false;
            }
        }

        void firstNode(int val) {
            if (isEmpty()) {
                head = new Node;
                head -> data = val;
                head -> next = NULL;
                len++;
            }
        }

        void insertAtMiddle(int val) {
            if (isEmpty()) {
                firstNode(val);
            }

            else {
                temp = head;

                if (len <= 1) {
                    cout << "Cannot enter value in Middle" << endl;
                }

                else {
                    int middle = len / 2;
                    for (int i = 1; i < middle; i++) {
                        temp = temp -> next;
                    }
                    Node* NewNode = new Node;
                    NewNode -> data = val;
                    NewNode -> next = temp -> next;
                    temp -> next = NewNode;
                    len++;
                }
            }
        }

        void insertAtEnd(int val) {
            if (isEmpty()) {
                firstNode(val);
            }

            else {
                temp = head;

                while (temp -> next != NULL) {
                    temp = temp -> next;
                }

                Node* NewNode = new Node;
                NewNode -> data = val;
                NewNode -> next = NULL;
                temp -> next = NewNode;
                len++;
            }
        }

        void insertAtHead(int val) {
            if (isEmpty()) {
                firstNode(val);
            }

            else {
                temp = head;
                Node* NewNode = new Node;

                NewNode -> data = val;
                NewNode -> next = temp;
                head = NewNode;
                len++;
            }
        }

        void printData(Node* head1) {
            if (isEmpty()) {
                cout << "LIST IS EMPTY" << endl;
            }

            else {
                temp = head1;
                while (temp != NULL) {
                    cout << temp -> data << endl;
                    temp = temp -> next;
                }
            }
        }

        // function to merge two linked list objects
        void merge(Node* head1, Node* head2) {
            if (head1 == NULL && head2 == NULL) {           // check if linked list is empty or not
                cout << "CANT MERGE, EMPTY LIST" << endl;
                return;
            }
            
            // if not empty then,
            else {
                temp = head1;

                while (temp -> next != NULL) {    // using while loop, will traverse the linked list until it reaches the last node
                    temp = temp -> next;
                }

                // after reaching the lsat node,
                temp -> next = head2;      // last node of the first object will connect with the first node of the second list
            }
        }

        // function to sort linked list
        void sorting(Node* h) {
            if (h == NULL) {            // checking if the linked list is empty or not
                cout << "Nothing to Sort" << endl;
            }

            // if not empty then,
            else {
                temp = h;
                
                while (temp != NULL) {          // while loop will run till it traverse the whole linked list
                    temp2 = temp -> next;

                    while (temp2 != NULL) {
                        if (temp -> data > temp2 -> data) {         // if data of first > second then swap
                            swapping (temp -> data, temp2 -> data);
                        }

                        else {
                            temp2 = temp2 -> next;                      // else go to next position
                        }
                    }

                    temp = temp -> next;
                }
            }
        }

        // function to swap two elements
        void swapping(int &a, int &b) {
            int c = a;
            a = b;
            b = c;
        }
};

int main() {
    LL obj;
    obj.insertAtEnd(10);
    obj.insertAtEnd(40);
    obj.insertAtEnd(30);
    obj.insertAtEnd(20);
    obj.printData(obj.head);
    obj.sorting(obj.head);
    cout << "\nAFTER SORTING" << endl;
    obj.printData(obj.head);

    cout << endl;

    LL obj2;
    obj2.insertAtEnd(50);
    obj2.insertAtEnd(80);
    obj2.insertAtEnd(70);
    obj2.insertAtEnd(60);
    obj2.printData(obj2.head);
    obj2.sorting(obj2.head);
    cout << "\nAFTER SORTING" << endl;
    obj2.printData(obj2.head);

    cout << endl;

    obj.merge(obj.head, obj2.head);

    cout << "AFTER MERGING" << endl;

    obj.printData(obj.head);

    return 0;
}