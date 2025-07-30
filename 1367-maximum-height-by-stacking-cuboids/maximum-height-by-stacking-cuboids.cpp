class Solution {
public:
    bool check(vector<int>& base, vector<int>& newBox) {
        return newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2];
    }

    int solve(int n, vector<vector<int>>& cuboids) {
        vector<int> curr(n + 1, 0), next(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int take = 0;
                if (j == -1 || check(cuboids[i], cuboids[j])) {
                    take = cuboids[i][2] + next[i + 1];
                }

                int notTake = next[j + 1];

                curr[j + 1] = max(take, notTake);
            }
            next = curr;
        }

        return next[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort each cuboid's dimensions
        for (auto& box : cuboids)
            sort(box.begin(), box.end());

        // Sort cuboids by dimension to make LIS logic valid
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids.size(), cuboids);
    }
};
