class Solution {
    int n;
    vector<vector<int>> fruits;
    vector<vector<int>> vis;
    int dp1[1001][1001];
    int dp2[1001][1001];



    int dfsBottomLeft(int i, int j) {
        if (i < n/2 || i >= n || j < 0 || j >= n || j >= i) return 0;
        if (vis[i][j]) return 0;
        if(dp1[i][j]!=-1)return dp1[i][j];
        vis[i][j] = 1;               
        int pick = fruits[i][j];
        int best = 0;
        best = max(best, dfsBottomLeft(i-1, j+1));
        best = max(best, dfsBottomLeft(i,   j+1));
        best = max(best, dfsBottomLeft(i+1, j+1));
        vis[i][j] = 0;               
        return dp1[i][j] = pick + best;
    }

    int dfsTopRight(int i, int j) {
        if (i < 0 || i >= n || j < n/2 || j >= n || j <= i) return 0;
        if (vis[i][j]) return 0;
        if(dp2[i][j]!=-1)return dp2[i][j];
        vis[i][j] = 1;               
        int pick = fruits[i][j];
        int best = 0;
        best = max(best, dfsTopRight(i+1, j-1));
        best = max(best, dfsTopRight(i+1, j  ));
        best = max(best, dfsTopRight(i+1, j+1));
        vis[i][j] = 0;               
        return dp2[i][j] = pick + best;
    }

public:
    int maxCollectedFruits(vector<vector<int>>& F) {
        fruits = F;
        n = fruits.size();
        vis.assign(n, vector<int>(n, 0));

        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += fruits[i][i];
            vis[i][i] = 1;
        }

        ans += dfsBottomLeft(n-1, 0);
        ans += dfsTopRight(0, n-1);

        return ans;
    }
};
