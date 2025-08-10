class Solution {
public:
    int dp[20005][2];
    int solve(int idx, vector<int>& v, int prevTaken, map<int,int>& mp) {
        if (idx >= (int)v.size()) return 0;
        if(dp[idx][prevTaken]!=-1) return dp[idx][prevTaken];
        int notpick = solve(idx + 1, v,0, mp);
        bool f = (prevTaken && idx > 0 && v[idx] == v[idx - 1] + 1);
        int pick = f ? INT_MIN : v[idx] * mp[v[idx]] + solve(idx + 1, v,1, mp);
        return dp[idx][prevTaken] = max(notpick, pick);
    }

    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        map<int,int> mp;
        vector<int> v;
        v.reserve(nums.size());
        for (int x : nums) {
            if (mp.find(x) == mp.end()) v.push_back(x);
            mp[x]++;
        }
        sort(v.begin(), v.end());

        return solve(0, v, 0, mp);
    }
};
