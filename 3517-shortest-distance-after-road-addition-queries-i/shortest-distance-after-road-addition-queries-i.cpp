class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        graph[i].push_back(i + 1);
    }
    
    auto dijkstra = [&](int start, int end) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.emplace(0, start);
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (int v : graph[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist[end];
    };

    vector<int> answer;
    for (const auto& query : queries) {
        int ui = query[0], vi = query[1];
        graph[ui].push_back(vi);
        int shortestPath = dijkstra(0, n - 1);
        answer.push_back(shortestPath);
    }

    return answer;
    }
};