class Solution {
public:
    int dp[301][301];
    const int mod = 1e9+7;
    int f(int n , int num , int x){
        if(n==0)return 1;
        if(n<0)return 0;
        int p = pow(num,x);
        if(p>n)return 0;
        if(dp[n][num]!=-1) return dp[n][num]%mod;
        int take = f(n-p,num+1,x);
        int nottake = f(n,num+1,x);
        return dp[n][num]=(take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return f(n,1,x);
    }
};