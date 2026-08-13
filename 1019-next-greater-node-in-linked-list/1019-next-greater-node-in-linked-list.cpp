class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> answer;

        ListNode* temp = head;

        while (temp != NULL) {
            answer.push_back(temp->val);
            temp = temp->next;
        }

        for (int i = 0; i < answer.size(); i++) {

            int original = answer[i];
            bool found = false;

            for (int j = i + 1; j < answer.size(); j++) {

                if (answer[j] > original) {
                    answer[i] = answer[j];
                    found = true;
                    break;
                }
            }

            if (!found) {
                answer[i] = 0;
            }
        }

        return answer;
    }
};