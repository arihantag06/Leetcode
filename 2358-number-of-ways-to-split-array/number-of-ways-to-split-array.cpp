class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long leftSum = 0;
        int ways = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                ways++;
            }
        }

        return ways;
    }
};
