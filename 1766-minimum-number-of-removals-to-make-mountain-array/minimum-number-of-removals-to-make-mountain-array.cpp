class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1), right(n, 1);

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                left[i] = max(left[i], left[j] + 1);
            }
        }
    }

    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[i]) {
                right[i] = std::max(right[i], right[j] + 1);
            }
        }
    }

    
    int max_mountain = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (left[i] > 1 && right[i] > 1) {
            max_mountain = max(max_mountain, left[i] + right[i] - 1);
        }
    }

    return n - max_mountain;
    }
};