class Solution {
public:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
     vector<pair<int,int>>adj[n];
        for (auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int , pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            int stops = it.first;
            int node = it.second.first;
            int distance = it.second.second;
            q.pop();
            
            if(stops>K)continue;
            for(auto x:adj[node]){
                int adjNode = x.first;
                int wt = x.second;
                if(distance + wt <dist[adjNode] && stops <=K){
                    dist[adjNode] = distance + wt;
                    q.push({stops+1,{adjNode , distance+wt}});
                }
            }
        }
        if(dist[dst]!=INT_MAX)return dist[dst];
        return -1;
}

};