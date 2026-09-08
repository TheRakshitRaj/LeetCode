class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;   
        ListNode* temp = curr;         

        while (curr != nullptr) {
            int sum = 0;

            while (curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }

            temp->val = sum;

            if (curr->next != nullptr) {
                temp->next = curr->next;  
                temp = temp->next;       
                curr = curr->next;       
            } else {
                temp->next = nullptr;     
                break;
            }
        }

        return head->next;
    }
};
