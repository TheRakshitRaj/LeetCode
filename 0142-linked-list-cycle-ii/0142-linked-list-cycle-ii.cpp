/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        map<ListNode*,int> m ; 
        while (slow != nullptr) {
            m[slow]++ ; 
            if(m[slow] > 1){
                return slow ;
            }
            slow = slow->next;

        }
        return nullptr ;
    }
};