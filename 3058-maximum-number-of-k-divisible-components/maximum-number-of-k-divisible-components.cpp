class Solution {
public:
    long long dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values,
            int k, int& maxComponents) {
        long long sum = values[node]; 

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                long long subtreeSum =
                    dfs(neighbor, node, adj, values, k, maxComponents);
                if (subtreeSum % k == 0) {
                    maxComponents++;
                } else {
                    sum += subtreeSum;
                }
            }
        }

        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int maxComponents = 0;
        long long totalSum = dfs(0, -1, adj, values, k, maxComponents);

        if (totalSum % k == 0) {
            maxComponents++;
        }

        return maxComponents;
    }
};