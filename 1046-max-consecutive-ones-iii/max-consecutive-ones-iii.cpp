class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, z=0,n = nums.size();
        int r = 0 ;
        int ans= 0 ;
        while(r<n){
            if(nums[r]==0) z++;
            if(z<=k){
                ans = max(ans,r-l+1);
            }
            while(z>k && l<n){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};