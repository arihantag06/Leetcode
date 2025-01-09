class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size());
        for (auto edge : edges) {
            adj[edge[0]].push_back(vals[edge[1]]);
            adj[edge[1]].push_back(vals[edge[0]]);
        }

        int maxSum = INT_MIN;
        for (int i = 0; i < adj.size(); i++) {
            vector<int> temp = adj[i];
            sort(rbegin(temp), rend(temp));
            int j = 0;
            int maxi = vals[i], n = temp.size();
            int sum = vals[i];
            while (j < n && j < k) { 
                sum += temp[j];
                maxi = max(maxi, sum); 
                j++;
            }
            maxSum = max(maxSum, maxi);
        }
        return maxSum;
    }
};
