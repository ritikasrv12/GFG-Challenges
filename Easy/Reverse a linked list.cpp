class Solution {
  public:
    Node* reverseList(struct Node* head) {
         Node *prev = NULL, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        // code here
    }
};
