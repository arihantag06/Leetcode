class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,pair<int,int>>>q;

        int n = isWater.size() , m = isWater[0].size();
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,-1,0,1};

        vector<vector<int>>height(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    height[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int h = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr<n && nr>=0 && nc<m & nc>=0 && height[nr][nc]==-1 ){
                    height[nr][nc] = h+1;
                    q.push({height[nr][nc] , {nr,nc}});
                }
            }

        }
        return height;
    }
};