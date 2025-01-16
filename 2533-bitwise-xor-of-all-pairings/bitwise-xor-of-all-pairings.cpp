class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int lenNums1 = nums1.size(),lenNums2 = nums2.size();
        int xorr1 = 0,xorr2=0;

        for(int i=0;i<lenNums1;i++){
            xorr1^=nums1[i];
        }

        for(int i=0;i<lenNums2;i++){
            xorr2^=nums2[i];
        }

        if(lenNums1%2==0) xorr2 = 0;
        if(lenNums2%2==0) xorr1 = 0;
        

        return xorr1^xorr2;

        
    }
};