class Solution {
public:
    int calPoints(vector<string>& operations) {
       vector <int> ans ;

       int sum = 0 ;

       for(int i = 0 ; i < operations.size() ; i++){
         if(operations[i] == "C"){
            ans.pop_back() ;
         }
         else if(operations[i] == "D"){
            int n = ans[ans.size()-1] * 2 ; 
            ans.push_back(n) ; 
         }
        else if(operations[i] == "+"){
            int m = ans[ans.size()-1] + ans[ans.size()-2] ; 
            ans.push_back(m) ;  
         }
         else{
            ans.push_back(stoi(operations[i])) ;
         }
       } 
       for(int i = 0 ; i < ans.size() ; i++){
          sum += ans[i] ;
       }

       return sum ;
    }
};