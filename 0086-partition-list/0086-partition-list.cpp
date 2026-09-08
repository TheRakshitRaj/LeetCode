class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        ListNode* curr = head;

        while (curr != NULL) {

            if (curr->val < x) {
                less->next = curr;
                less = less->next;
            }
            else {
                greater->next = curr;
                greater = greater->next;
            }

            curr = curr->next;
        }

        greater->next = NULL;

        less->next = greaterHead->next;

        return lessHead->next;
    }
};