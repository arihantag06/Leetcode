class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int count=0;
        int m  = words.size();
        for(int i=0;i<m;i++){
            string t = words[i];
            if(t.substr(0,n)==pref)count++;
        }
        return count;
    }
};