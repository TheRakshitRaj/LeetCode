class Solution {
public:
    long long sumAndMultiply(int n) {
        long long newNum = 0;
        long long sum = 0;

        string str = to_string(n);

        for(char c : str) {
            if(c != '0') {
                int digit = c - '0';

                newNum = newNum * 10 + digit;
                sum += digit;
            }
        }

        return newNum * sum;
    }
};