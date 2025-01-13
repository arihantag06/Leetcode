class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {1, 0, -1, 0};
        int m = moveTime.size();
        int n = moveTime[0].size();
        
        priority_queue<pair<int,pair<int,int>>, 
                      vector<pair<int,pair<int,int>>>, 
                      greater<pair<int,pair<int,int>>>> minheap;
        minheap.push({0, {0, 0}});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        
        while(!minheap.empty()) {
            auto p = minheap.top();
            int time = p.first;
            int row = p.second.first;
            int col = p.second.second;
            minheap.pop();
            
            if(row == m-1 && col == n-1) return time;
            
            for(int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]) {
                    minheap.push({1 + max(time, moveTime[nrow][ncol]), {nrow, ncol}});
                    visited[nrow][ncol] = true;
                }
            }
        }
        return -1;
    }
};