class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL)
            return NULL;

        ListNode* temp = head;
        int count = 1;

     while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }

        int ref = count - n;

        if (ref == 0) {
            return head->next;
        }

        temp = head;

        for (int i = 1; i < ref; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};