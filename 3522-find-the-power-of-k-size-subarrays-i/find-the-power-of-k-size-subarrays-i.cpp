class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int l = 0, r = k - 1;

        while (r < n) {
            bool isConsecutive = true;
            for (int i = l; i < r; i++) {
                if (nums[i] + 1 != nums[i + 1]) {
                    isConsecutive = false;
                    break;
                }
            }

            if (isConsecutive) {
                int maxInd = l;
                for (int i = l + 1; i <= r; i++) {
                    if (nums[i] > nums[maxInd]) {
                        maxInd = i;
                    }
                }
                res.push_back(nums[maxInd]);
            }
            else res.push_back(-1);
            l++;
            r++;
        }

        return res;
    }
};