class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> mp; 
        int maxSum = -1;
        
        for (int num : nums) {
            int sum = 0, temp = num;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            
            auto& [max1, max2] = mp[sum]; 
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }

            if (max1 && max2) {
                maxSum = max(maxSum, max1 + max2);
            }
        }
        
        return maxSum;
    }
};
