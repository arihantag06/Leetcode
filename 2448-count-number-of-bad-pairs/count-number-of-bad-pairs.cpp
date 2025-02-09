class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPairs = 1LL*n*(n-1)/2;
        map<long long,set<long long>>mp;
        for(int i=0;i<n;i++){
            int diff = nums[i]-i;
            mp[diff].insert(i);
        }

        long long tot = 0;
        for(auto it:mp){
            int sz = it.second.size();
            tot+= 1LL*sz*(sz-1)/2;
        }

        badPairs-= tot;
        return badPairs;
    }
};