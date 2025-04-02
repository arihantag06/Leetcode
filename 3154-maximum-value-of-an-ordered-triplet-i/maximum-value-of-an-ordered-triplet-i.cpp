class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long imax=0,dmax=0,res=0;
        for(int k=0;k<nums.size();k++){
            res = max(res,dmax*nums[k]);
            dmax = max(dmax,imax-nums[k]);
            imax = max(imax,1LL*nums[k]);
        }
        return res;
    }
};