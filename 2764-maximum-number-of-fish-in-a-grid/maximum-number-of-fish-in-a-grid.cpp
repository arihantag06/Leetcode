class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    
    int dfs(int r, int c, vector<vector<int>>& grid, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] <= 0) 
            return 0;

        int fish = grid[r][c];
        grid[r][c] = 0; 

        int totalFish = fish;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            totalFish += dfs(nr, nc, grid, n, m);
        }

        return totalFish;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxi = max(maxi, dfs(i, j, grid, n, m));
                }
            }
        }

        return maxi;
    }
};
