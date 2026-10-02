class Solution {
public:
    int smallestIndex(vector<int>& nums) {

         int sum = 0 ;

        for(int i = 0 ; i < nums.size() ; i++){
            while(nums[i] > 0){
              int digit = nums[i] % 10 ;
             sum += digit ;
              nums[i] /= 10 ;
            }
            if(sum == i){
                return i ;
            }
            else{
                sum = 0 ;
            }
        }
        return -1 ;
    }
};