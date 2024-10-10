class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int minKposition = -1;
        int maxKposition = -1;
        int culpritIdx = -1;
        int n = nums.size();

        long long count = 0;


        for(int i=0;i<n;i++){
            if(nums[i]==maxK){
                maxKposition = i;
            }
            if(nums[i]==minK){
                minKposition = i;
            }

            if(nums[i]>maxK || nums[i]<minK){
                culpritIdx = i;
            }

            if(minKposition!=-1 && maxKposition!=-1){
                count+=max(0, min(maxKposition,minKposition)-culpritIdx);
            }
        }

        return count;

    }
};