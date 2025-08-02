class Solution {
public:
    int f(vector<int>& nums, int k){
        int odd = 0, n = nums.size(),r=0,l=0,cnt=0;
        while(r<n){
            if(nums[r]%2!=0)odd++;
            while(odd>k){
                if(nums[l]%2!=0)odd--;
                l++;
            }
            cnt+=(r-l)+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};