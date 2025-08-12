class Solution {
public:
    int dp[301][301];
    const int mod = 1e9+7;
    int f(int ind, vector<int>&a, int target){
        if(target==0)return 1;
        if(ind<0 || target<0)return 0;
        if(dp[ind][target]!=-1) return dp[ind][target]%mod;
        int take = f(ind-1,a,target-a[ind]);
        int nottake = f(ind-1,a,target);
        return dp[ind][target]=(take+nottake)%mod;
    }
    int pow(int num, int p){
        int prod = 1;
        while(p--){
            prod = prod*num;
        }
        return prod;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        vector<int>a;
        for(int i=1;i<=300;i++){
            int val = pow(i,x);
            if(val>n)break;
            a.push_back(val);
        }
        int sz = a.size();
        
        return f(sz-1,a,n);
    }
};