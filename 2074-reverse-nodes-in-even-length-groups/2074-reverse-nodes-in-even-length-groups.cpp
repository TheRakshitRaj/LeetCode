class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        ListNode* curr = head;

        int groupSize = 1;

        while (curr != nullptr) {

            // Find actual size of current group
            int count = 0;
            ListNode* temp = curr;

            while (temp != nullptr && count < groupSize) {
                temp = temp->next;
                count++;
            }

            // Even group → reverse
            if (count % 2 == 0) {

                ListNode* nextGroup = temp;

                ListNode* prev = nextGroup;
                ListNode* node = curr;

                for (int i = 0; i < count; i++) {
                    ListNode* next = node->next;
                    node->next = prev;
                    prev = node;
                    node = next;
                }

                // Connect previous group to reversed group
                prevGroup->next = prev;

                // curr is now the LAST node of reversed group
                prevGroup = curr;

                curr = nextGroup;
            }
            else {

               
                for (int i = 0; i < count; i++) {
                    prevGroup = curr;
                    curr = curr->next;
                }
            }

            groupSize++;
        }

        return dummy.next;
    }
};