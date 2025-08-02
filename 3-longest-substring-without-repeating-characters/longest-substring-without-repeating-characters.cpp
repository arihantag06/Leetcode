class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int len=0;
        int l=0;
        int n = s.length();
        for(int r=0;r<n;r++){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }
            hash[s[r]] = r;
            len = max(len,r-l+1);
        }
        return len;
    }
};