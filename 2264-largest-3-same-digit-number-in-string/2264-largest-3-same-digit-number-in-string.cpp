class Solution {
public:
    string largestGoodInteger(string num) {
       string val = "" ;
       string max = "" ;

       for(int i = 0 ; i < num.length()-2 ; i++){
          if(num[i] == num[i+1] && num[i] == num[i+2]){
            val = num.substr(i,3) ;
            if(val > max){
                max = val ;
            }
          }
         
       } 
      
       return max ;
    }
};