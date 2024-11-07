class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        int n =candidates.size();
        for(int i=0;i<24;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(candidates[j]&(1<<i)){
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }

        return ans;
    }
};