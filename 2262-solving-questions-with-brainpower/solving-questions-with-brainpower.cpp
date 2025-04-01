class Solution {
public:
    long long dp[1000001];
    long long solve(int idx , int N ,vector<vector<int>>& questions){
        if(idx>=N) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int pts = questions[idx][0];
        int bpow = questions[idx][1];
        long long choose = pts + solve(idx+bpow+1,N,questions);
        long long skip = solve(idx+1,N,questions);
        return dp[idx]=max(choose,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(0,questions.size(),questions);
    }
};