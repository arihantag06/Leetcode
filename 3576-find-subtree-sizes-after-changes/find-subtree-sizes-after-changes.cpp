class Solution {
public:
    int f(int nd ,vector<vector<int>>&adj,vector<int>&res) {
            int size = 1;
            for (int it : adj[nd]) {
                size += f(it,adj,res);
            }
            res[nd] = size;
            return size;
    };
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int N = parent.size();
        vector<int> temp = parent;
        for (int node = 1; node < N; ++node) {
            int ancestor = parent[node];
            while (ancestor != -1 && s[ancestor] != s[node]) {
                ancestor = parent[ancestor];
            }
            if (ancestor != -1) {
                temp[node] = ancestor;
            }
        }
        vector<vector<int>> adj(N);
        for (int i = 1; i < N; ++i) {
            adj[temp[i]].push_back(i);
        }
        
        vector<int> res(N, 0);
        f(0,adj,res);
        return res;
    }
};