class Solution {
public:
    int dp[101];
    int solve(int idx , string s){
        if(s[idx]=='0')return 0;
        if(idx==s.size())return 1;
        if(dp[idx]!=-1)return dp[idx];
        int two = -1;
        if(idx+1!=s.size() || s[idx]=='0'){
            two = ((s[idx]-'0')*10) + (s[idx+1]-'0');
        }

        if(two!=-1 && two<=26){
            return dp[idx]= solve(idx+2,s) + solve(idx+1,s);
        }
        return dp[idx]= solve(idx+1,s);
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};