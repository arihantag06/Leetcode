class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int left = 1, count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] >= nums[i + 1]) count = 1; 
            else count++;
            left = max(left, count);
        }

        int right = 1;
        count = 1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] >= nums[i - 1]) count = 1; 
            else count++;
            right = max(right, count);
        }

        return max(left, right);
    }
};
