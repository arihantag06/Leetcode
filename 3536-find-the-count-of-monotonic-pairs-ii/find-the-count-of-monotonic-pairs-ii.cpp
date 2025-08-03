class Solution {
public:
    int M = 1e9 + 7;
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1005, 0));

        for (int curr = 0; curr <= nums[0]; curr++)
            dp[0][curr] = 1;

        for (int i = 1; i < n; i++) {
            int ways = 0;
            int prev = 0;
            for (int curr = 0; curr <= nums[i]; curr++) {
                if (prev <= min(curr, curr + nums[i - 1] - nums[i])) {
                    ways = (ways % M + dp[i - 1][prev] % M) % M;
                    prev++;
                }
                dp[i][curr] = ways;
            }
        }
        int total_count = 0;
        for (int curr = 0; curr <= 1000; curr++) {
            total_count = (total_count % M + dp[n - 1][curr] % M) % M;
        }
        return total_count;
    }
};