class Solution {
public:
    int dp[101];
    int solve(int index, vector<int>&nums){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        int take = nums[index] + solve(index+2,nums);
        int nottake = solve(index+1,nums);
        return dp[index] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};