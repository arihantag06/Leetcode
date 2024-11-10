
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int orVal = 0;  
        vector<int> setBits(32, 0);  
        int i = 0, j = 0, n = nums.size();
        int mini = INT_MAX;

        while (j < n) {
            
            orVal |= nums[j];
            for (int q = 0; q < 32; q++) {
                if (nums[j] & (1 << q)) {
                    setBits[q]++;
                }
            }

            
            while (i<=j && orVal >= k) {
                mini = min(mini, j - i + 1);

                
                for (int q = 0; q < 32; q++) {
                    if (nums[i] & (1 << q)) {
                        setBits[q]--;
                    }
                }

                
                int newOrVal = 0;
                for (int q = 0; q < 32; q++) {
                    if (setBits[q] > 0) {
                        newOrVal |= (1 << q);
                    }
                }
                
                orVal = newOrVal;
                i++; 
            }
            j++;  
        }

        return (mini == INT_MAX) ? -1 : mini;
    }
};
