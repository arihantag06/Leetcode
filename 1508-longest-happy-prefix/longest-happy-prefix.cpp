class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int>lps(n,0);
        lps[0] = 0;
        int i=1; 
        int len = 0;
        while(i < s.length()){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0) len = lps[len-1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int end = lps[n-1];
        return s.substr(0,end);
    }
};