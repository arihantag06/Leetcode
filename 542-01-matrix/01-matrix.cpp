class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                } else {
                    res[i][j]=-1;
                }
            }
        }

        vector<pair<int,int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto tp = q.front();
            int r = tp.first;
            int c = tp.second;
            q.pop();
            for(auto dir:dirs){
                int nr = r+dir.first;
                int nc = c+dir.second;

                if(nr<n && nr>=0 && nc<m && nc>=0 && res[nr][nc]==-1){
                    res[nr][nc] = res[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
};