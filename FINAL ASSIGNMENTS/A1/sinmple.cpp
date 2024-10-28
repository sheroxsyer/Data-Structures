#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void swapNodes(ListNode* head, int pos1, int pos2) {
    if (pos1 == pos2) {
        // nothing to swap
        return;
    }

    // find the nodes to be swapped and their previous nodes
    ListNode *node1 = head, *prev1 = NULL;
    for (int i = 1; i < pos1 && node1; i++) {
        prev1 = node1;
        node1 = node1->next;
    }
    ListNode *node2 = head, *prev2 = NULL;
    for (int i = 1; i < pos2 && node2; i++) {
        prev2 = node2;
        node2 = node2->next;
    }

    // check if positions are valid
    if (!node1 || !node2) {
        return;
    }

    // swap the nodes by updating the next pointers
    if (prev1) {
        prev1->next = node2;
    } else {
        head = node2;
    }
    if (prev2) {
        prev2->next = node1;
    } else {
        head = node1;
    }
    ListNode* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    swapNodes(head, 2, 4);

    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;

    return 0;
}
