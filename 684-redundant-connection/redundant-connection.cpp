class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (parent[node] != node) {
            parent[node] = find(parent[node], parent); 
        }
        return parent[node];
    }

    void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);

        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), rank(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            if (find(a, parent) == find(b, parent)) {
                return edge; 
            }
            unionSets(a, b, parent, rank);
        }

        return {};
    }
};
