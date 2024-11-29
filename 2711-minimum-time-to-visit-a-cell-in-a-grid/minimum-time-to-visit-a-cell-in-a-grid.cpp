class Solution {
public:
    #define P pair<int,pair<int,int>>
    vector<vector<int>>directions ={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();

        if(grid[0][1]>1 && grid[1][0]>1) return -1; //base case

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        result[0][0]=0;

        vector<vector<int>>vis(m,vector<int>(n,false));

        while(!pq.empty()){
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row==m-1 && col==n-1)return result[m-1][n-1];

            if(vis[row][col]==true)continue; 
            vis[row][col]=true;

            for(auto&d:directions){
                int nrow = row + d[0];
                int ncol = col + d[1];

                if(nrow>=m || nrow<0 || ncol>=n || ncol<0) continue;

                if(grid[nrow][ncol]<=time+1){
                    pq.push({time+1,{nrow,ncol}});
                    result[nrow][ncol] = time+1;
                }
                else if((grid[nrow][ncol]-time)%2==0){
                    pq.push({grid[nrow][ncol]+1,{nrow,ncol}});
                    result[nrow][ncol] = grid[nrow][ncol]+1;
                }
                else {
                    pq.push({grid[nrow][ncol],{nrow,ncol}});
                    result[nrow][ncol] = grid[nrow][ncol];
                }
            }
        }
        return result[m-1][n-1];
    }
};