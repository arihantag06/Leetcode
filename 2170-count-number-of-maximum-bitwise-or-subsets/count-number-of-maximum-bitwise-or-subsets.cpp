class Solution {
public:
    int solve(int idx , vector<int>&nums,int maxOr , int n,int temp){
        if(idx>=n)return temp==maxOr?1:0;
        int take = solve(idx+1,nums,maxOr,n,temp|nums[idx]);
        int nottake = solve(idx+1,nums,maxOr,n,temp);
        return take+nottake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        long long maxOr = 0;
        for(auto i:nums)maxOr|=i;
        return solve(0,nums,maxOr,n,0);
    }
};