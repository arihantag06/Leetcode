class Solution {
public:
    int bits(int num) {
        return __builtin_popcount(num);  // Efficient set bit count
    }
    
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> setBits(n);
        
        
        for(int i = 0; i < n; i++) {
            setBits[i] = bits(nums[i]);
        }
        
        bool swapped;
        do {
            swapped = false;
            for(int i = 0; i < n - 1; i++) {
                if (setBits[i] == setBits[i + 1] && nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                    swap(setBits[i], setBits[i + 1]);  
                    swapped = true;
                } else if (setBits[i] != setBits[i + 1] && nums[i] > nums[i + 1]) {
                    return false; 
                }
            }
        } while (swapped); 
        
        
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) return false;
        }
        return true;
    }
};
