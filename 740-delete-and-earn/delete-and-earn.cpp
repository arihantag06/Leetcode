class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int maxi = 0;
        for(int i=0; i < nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        vector<int> dp(maxi + 4, 0);
        for(int i=0; i < nums.size(); i++){
            dp[nums[i]] += nums[i];
        }
        for(int i=maxi; i > -1; i--){
            dp[i] += max(dp[i + 2], dp[i + 3]);
        }
        return max({dp[0], dp[1]});
    }
};