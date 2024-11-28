class Solution {

private:
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int minimumObstacles(vector<vector<int>>& grid) { 
        int n = grid.size() , m =grid[0].size();
        vector<vector<int>>minObs(n,vector<int>(m,INT_MAX));

        minObs[0][0] = grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({minObs[0][0],0,0});
                //obsCount , row,col
        while(!pq.empty()){
            vector<int>curr = pq.top();pq.pop();
            int obs = curr[0] , row = curr[1],col=curr[2];

            if(row==n-1 && col==m-1)return obs;

            for(auto&d:directions){
                int nrow = row+d[0],ncol = col+d[1];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    int newObs = obs+grid[nrow][ncol];

                    if(newObs<minObs[nrow][ncol]){
                        minObs[nrow][ncol] = newObs;
                        pq.push({newObs,nrow,ncol});
                    }
                }
            }

        }
        return minObs[n-1][m-1];

    }
};