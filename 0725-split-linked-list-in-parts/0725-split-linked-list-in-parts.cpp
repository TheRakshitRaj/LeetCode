/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);

        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        int baseSize = count / k;
        int extra = count % k;

        temp = head;
        for (int i = 0; i < k && temp != nullptr; i++) {
            ans[i] = temp; 
            int partSize = baseSize + (i < extra ? 1 : 0);

            for (int j = 1; j < partSize; j++) {
                temp = temp->next;
            }

            // cut the list
            ListNode* nextPart = temp->next;
            temp->next = nullptr;
            temp = nextPart;
        }

        return ans;
    }
};
