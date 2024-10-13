class Solution {
public:
    int dp[46];
    
    int f(int n){
        if(dp[n]!=-1)return dp[n];
        if(n<=1)return 1;
        return dp[n]=f(n-1) + f(n-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n);
    }

};