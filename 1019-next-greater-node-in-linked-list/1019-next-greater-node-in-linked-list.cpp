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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        while(head != nullptr){
            ans.push_back(head->val);
            head = head->next;
        }

        for(int i=0; i<ans.size(); i++){
            int count = 0;
            for(int j=i+1; j<ans.size(); j++){
                if(ans[i] < ans[j]){
                    ans[i] = ans[j];
                    count = 1;
                    break;
                }
            }
            if(count == 0){
                ans[i] = 0;
            }
        }


        return ans;
    }
};