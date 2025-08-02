class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 , n = s.size();
        int maxi =0;
        map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            while(mp[s[r]]>1 && l<n){
                mp[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};