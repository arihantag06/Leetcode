class Solution {
public:
    int dp[101];
    int solve(int idx , string s){
        if(idx==s.size())return 1;
        if(dp[idx]!=-1)return dp[idx];
        
        int res = 0;
        if(s[idx]!='0'){
            res+=solve(idx+1,s);
        }
        if(idx+1<s.size() && (s[idx]=='1' || s[idx]=='2' && s[idx+1]<='6')){
            res+=solve(idx+2,s);
        }
        return dp[idx] = res;
       
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};