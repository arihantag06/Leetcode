class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int l=0,r=0,n = fruits.size();
        int res = INT_MIN;
        while(r<n){
            mp[fruits[r]]++;
            while(l<n && mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};