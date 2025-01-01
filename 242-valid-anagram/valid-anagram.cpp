class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length(),m=t.length();
        if(n!=m)return false;
        vector<int>freqS(26,0),freqT(26,0);
        for(int i=0;i<n;i++){
        freqS[s[i]-'a']++;
        freqT[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freqS[i]!=freqT[i])return false;
        }
        return true;
    }
};