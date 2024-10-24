class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorr=0;
        for(auto it:nums)xorr^=it;
        if(xorr==0)return true;
        int n=nums.size();
        if(n%2==0)return true;
        else return false;
    }
};