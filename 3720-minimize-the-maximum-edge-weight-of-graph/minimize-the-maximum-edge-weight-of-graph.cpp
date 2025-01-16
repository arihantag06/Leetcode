class Solution {
public:
    int dfs(int i,int m,vector<vector<pair<int,int>>>&adj , vector<int>&vis){
        int res = vis[i] = 1;
        for(auto p : adj[i]){
            int w = p.second;
            int adjNode = p.first;
            if(w<=m && !vis[adjNode]){
                res+=dfs(adjNode,m,adj,vis);
            }
        }
        return res;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e: edges){
            int a  = e[0];
            int b  = e[1];
            int w  = e[2];
            adj[b].push_back({a,w});
        }
        int l =1,r=1000001;
        while(l<r){
            int m = l + (r-l)/2;
            if(vector<int>vis(n);dfs(0,m,adj,vis)==n){
                r = m;
            } else {
                l = m+1;
            }
        }

        return l==1000001? -1 :l;
    }
};