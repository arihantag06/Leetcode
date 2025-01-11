class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<int>> adj(2 * n);
        for (auto& edge : redEdges) {
            int u = edge[0];
            int v_dash = edge[1] + n; 
            adj[u].push_back(v_dash);
        }
        for (auto& edge : blueEdges) {
            int u_dash = edge[0] + n; 
            int v = edge[1];
            adj[u_dash].push_back(v);
        }

        
        vector<int> dist(2 * n, -1);
        dist[0] = dist[n] = 0; 

        queue<pair<int, int>> q;
        q.push({0, 0}); 
        q.push({n, 0}); 

       
        while (!q.empty()) {
            int node = q.front().first;
            int wt = q.front().second;
            q.pop();

            for (int adjNode : adj[node]) {
                if (dist[adjNode] == -1) { 
                    dist[adjNode] = wt + 1;
                    q.push({adjNode, wt + 1});
                }
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            int redDist = dist[i];
            int blueDist = dist[i + n];
            if (redDist == -1 && blueDist == -1) {
                result[i] = -1;
            } else if (redDist == -1) {
                result[i] = blueDist;
            } else if (blueDist == -1) {
                result[i] = redDist;
            } else {
                result[i] = min(redDist, blueDist);
            }
        }

        return result;
    }
};
