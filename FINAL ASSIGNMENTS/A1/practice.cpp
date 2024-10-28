#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void swapNodes(int lPos, int rPos, ListNode* head) {
    if (lPos == rPos) return; // nothing to swap
    ListNode *lNode = head, *rNode = head, *prevL = NULL, *prevR = NULL;
    int count = 1;
    while (head != NULL) {
        if (count == lPos) {
            lNode = head;
        }
        else if (count == rPos) {
            rNode = head;
        }
        if (lNode == NULL) {
            prevL = head;
        }
        prevR = head;
        head = head->next;
        count++;
    }
    // Check if positions are valid
    if (lNode == NULL || rNode == NULL) {
        cout << "Invalid positions" << endl;
        return;
    }
    // Swap nodes by updating next pointers
    if (prevL != NULL) prevL->next = rNode;
    else head = rNode;
    if (prevR != NULL) prevR->next = lNode;
    else head = lNode;
    ListNode* temp = lNode->next;
    lNode->next = rNode->next;
    rNode->next = temp;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    swapNodes(2, 5, head);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
