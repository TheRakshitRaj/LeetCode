class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int diff = (sumB - sumA) / 2;

        for(int a : aliceSizes) {

            int b = a + diff;

            for(int x : bobSizes) {
                if(x == b) {
                    return {a, b};
                }
            }
        }

        return {};
    }
};