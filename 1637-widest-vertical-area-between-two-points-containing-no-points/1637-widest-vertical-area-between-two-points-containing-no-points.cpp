class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int maxD = 0 ;

        for(int i = 0 ; i < points.size()-1 ; i++){
            int diff = points[i+1][0] - points[i][0];

            maxD = max(diff,maxD) ;
        }

        return maxD ;
    }
};