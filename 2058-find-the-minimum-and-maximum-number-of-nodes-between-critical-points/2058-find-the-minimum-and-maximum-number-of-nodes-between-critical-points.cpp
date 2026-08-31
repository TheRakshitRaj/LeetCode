class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int count = 2;

        while(curr->next != NULL) {

            if((curr->val > prev->val && curr->val > curr->next->val) ||
               (curr->val < prev->val && curr->val < curr->next->val)) {
                
                critical.push_back(count);
            }

            prev = curr;
            curr = curr->next;
            count++;
        }

        if(critical.size() < 2)
            return {-1, -1};

        int minDis = INT_MAX;

        for(int i = 1; i < critical.size(); i++) {
            minDis = min(minDis, critical[i] - critical[i - 1]);
        }

        int maxDis = critical.back() - critical.front();

        return {minDis, maxDis};
    }
};