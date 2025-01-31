class DisjointSet{
    
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        } 
    }

    int findUPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};

class Solution {
private:
    bool isValid(int nr , int nc, int n){
        return nr>=0 && nr<n && nc>=0 && nc<n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        // step-1
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(isValid(nr,nc,n) && grid[nr][nc]==1){
                        int node = row*n+col;
                        int adjNode = nr*n+nc;
                        ds.unionBySize(node,adjNode);
                    }
                }
            }
        }
        // step-2
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;
                for(int i=0;i<4;i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(isValid(nr,nc,n)){
                        if(grid[nr][nc]==1){
                            components.insert(ds.findUPar(nr*n+nc));
                        }
                    }
                }
                int sz=1;
                for(auto it:components){
                    sz+=ds.size[it];
                }
                mx = max(mx,sz);
            }
        }
        for(int cellNo=0;cellNo<n*n;cellNo++){
            mx = max(mx,ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};