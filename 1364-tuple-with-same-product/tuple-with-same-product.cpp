class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        for (auto& it : mp) {
            int num = it.second;
            count += (num * (num - 1) / 2) * 8;
        }

        return count;
    }
};
