class Solution {
public:
    string reorganizeString(string s) {
       
        int freq[26] = {0};

        for(char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = 0 ;
        int maxChar = 0 ;

        for(int i = 0 ; i< 26 ; i++){
            if(freq[i] > maxFreq){
                maxFreq = freq[i];
                maxChar = i ;
            }
        }

        if(maxFreq > (s.length()+1) / 2 ){
            return "" ;
        }

        string ans(s.length() , ' ') ;
        int index = 0 ;

          while(freq[maxChar] > 0) {
            ans[index] = char(maxChar + 'a');
            index += 2;
            freq[maxChar]--;
        }
          for(int i = 0; i < 26; i++) {

            while(freq[i] > 0) {

                if(index >= s.length()) {
                    index = 1;
                }

                ans[index] = char(i + 'a');

                index += 2;
                freq[i]--;
            }
        }
        return ans ;

    }
};