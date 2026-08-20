class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        int num1;
        int num2;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                arr1.push_back(nums[i]);
                num1 = nums[i];
            }

           else if (i == 1) {
                arr2.push_back(nums[i]);
                num2 = nums[i];
            }

            if (num1 > num2 && i >= 2) {
                arr1.push_back(nums[i]);
                num1 = nums[i];

            } 
            else if(num1 < num2 && i >= 2) {
                arr2.push_back(nums[i]);
                num2 = nums[i];
            }
        }
        vector<int> merged = arr1;
        merged.insert(merged.end(), arr2.begin(), arr2.end());

        return merged;
    }
};