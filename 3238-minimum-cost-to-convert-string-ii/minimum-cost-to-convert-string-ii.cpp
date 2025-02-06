class Solution {
    unordered_map<string, int> indices;
    vector<vector<long long>> costs;
 
    void assignIndices(const vector<string>& original, const vector<string>& changed) {
        unordered_set<string> distinctStrings(original.begin(), original.end());
        distinctStrings.insert(changed.begin(), changed.end());

        int index = 0;
        for (const string& str : distinctStrings) {
            indices[str] = index++;
        }
    }

    void buildGraph(const vector<string>& original, const vector<string>& changed, const vector<int>& cost, const unordered_map<string, int>& indices, vector<vector<pair<int, int>>>& graph) {
        int n = original.size();

        for (int i = 0; i < n; ++i) {
            int u = indices.at(original[i]);
            int v = indices.at(changed[i]);
            int w = cost[i];
            graph[u].emplace_back(v, w);
        }
    }

    vector<long long> dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int n) {
        vector<long long> dist(n, 1000000000000L);
        dist[source] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if (cost > dist[u]) continue;

            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int edgeCost = neighbor.second;

                if (dist[u] + edgeCost < dist[v]) {
                    dist[v] = dist[u] + edgeCost;
                    pq.push({-dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<vector<long long>> minCostMatrix(const vector<string>& original, const vector<string>& changed, const vector<int>& cost) {
        assignIndices(original,changed);
        int n = indices.size();

        // Build graph with integer indices
        vector<vector<pair<int, int>>> graph(n);
        buildGraph(original, changed, cost, indices, graph);

        // Initialize cost matrix with all distances set to infinity
        vector<vector<long long>> costMatrix(n, vector<long long>(n, 1000000000000L));

        // Run Dijkstra's algorithm for each node
        for (int i = 0; i < n; ++i) {
            vector<long long> distances = dijkstra(graph, i, n);

            // Update the cost matrix
            for (int j = 0; j < n; ++j) {
                costMatrix[i][j] = distances[j];
            }
        }

        return costMatrix;
    }
   
    long long minCost(string& source, string& target) {
        int n = source.size();

        // Collect unique lengths present in the indices map
        set<int> uniqueLengths;
        for (const auto& entry : indices) {
            uniqueLengths.insert(entry.first.size());
        }

        // Initialize dp array
        vector<long long> dp(n + 1, 1e12);

        // Base case: converting empty string to empty string costs 0
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int len : uniqueLengths) {
                if (i - len >= 0) {
                    string substrSource = source.substr(i - len, len);
                    string substrTarget = target.substr(i - len, len);

                    if (substrSource == substrTarget) {
                        dp[i] = min(dp[i], dp[i - len]);
                    } else if (indices.find(substrSource) != indices.end() && indices.find(substrTarget) != indices.end()) {
                        int u = indices[substrSource];
                        int v = indices[substrTarget];
                        dp[i] = min(dp[i], dp[i - len] + costs[u][v]);
                    }
                }
            }
            if (source[i-1]==target[i-1])
                dp[i] = min(dp[i],dp[i-1]);
        }

        return (dp[n] >= 1e12) ? -1 : dp[n];
    }
    
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        costs = minCostMatrix(original, changed, cost);
        return minCost(source,target);
    }
};