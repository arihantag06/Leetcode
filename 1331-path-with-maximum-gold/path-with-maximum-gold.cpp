class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)return 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxGold = max({
            dfs(i - 1, j, grid), 
            dfs(i + 1, j, grid), 
            dfs(i, j - 1, grid), 
            dfs(i, j + 1, grid)  
        });
        grid[i][j] = gold;
        return gold + maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {  
                    res = max(res, dfs(i, j, grid));
                }
            }
        }

        return res;
    }
};
