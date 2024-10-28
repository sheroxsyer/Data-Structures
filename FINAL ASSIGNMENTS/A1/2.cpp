#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swapNodes(int pos1, int pos2, Node* head) {
    if (pos1 == pos2) return; // nothing to swap
    Node *node1 = head, *node2 = head, *prev1 = NULL, *prev2 = NULL;
    int count = 1;
    while (head != NULL) {
        if (count == pos1) {
            node1 = head;
        }
        else if (count == pos2) {
            node2 = head;
        }
        if (node1 == NULL) {
            prev1 = head;
        }
        prev2 = head;
        head = head->next;
        count++;
    }
    // Check if positions are valid
    if (node1 == NULL || node2 == NULL) {
        cout << "Invalid positions" << endl;
        return;
    }
    // Swap nodes by updating next pointers
    if (prev1 != NULL) prev1->next = node2;
    else head = node2;
    if (prev2 != NULL) prev2->next = node1;
    else head = node1;
    Node* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

int main() {
    // Example usage
    Node* head = new Node({1, new Node({2, new Node({3, new Node({4, new Node({5, NULL})})})})});

    swapNodes(2, 5, head);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
