class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0;
        int maxi = 0;
        int n =values.size();
        for(int i=0;i<n;i++){
            res =max(res,maxi+values[i]-i);
            maxi = max(maxi,values[i]+i);
            
        }
        return res;
    }
};