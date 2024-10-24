class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<vector<double>>> memo;

    double solve(int row, int col, int n, int k) {
        if (row < 0 || row >= n || col < 0 || col >= n) return 0;
        if (k == 0) return 1;
        if (memo[row][col][k] != -1) return memo[row][col][k];

        vector<pair<int, int>> moves = {{-2, -1}, {-2, +1}, {-1, -2}, {-1, +2}, 
                                        {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}};
        double prob = 0;
        for (auto move : moves) {
            int newRow = row + move.first;
            int newCol = col + move.second;
            prob += solve(newRow, newCol, n, k - 1) / 8.0;
        }

        return memo[row][col][k] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {
        memo = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return solve(row, column, n, k);
    }
};
