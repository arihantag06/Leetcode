class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums),end(nums));
        
        unordered_map<int, int> streak;
        int longestStreak = 1;

        for (int num : nums) {
            int prev = sqrt(num);
            if (prev * prev == num && streak.count(prev)) {
                streak[num] = streak[prev] + 1;
            } else {
                streak[num] = 1;
            }
            longestStreak = max(longestStreak, streak[num]);
        }

        return longestStreak > 1 ? longestStreak : -1; 
    }
};
