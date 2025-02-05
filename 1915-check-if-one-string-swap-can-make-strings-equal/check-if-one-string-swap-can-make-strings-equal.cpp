class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0 , n = s1.length();
        vector<int>hash1(26,0) , hash2(26,0);
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])count++;
            hash1[s1[i]-'a']++;
            hash2[s2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])return false;
        }
        return count==2 || count==0;
    }
};