class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxi = INT_MIN, k = nums.size();
        
        
        priority_queue<pair<int,pair<int,int>>, 
                       vector<pair<int,pair<int,int>>>, 
                       greater<pair<int,pair<int,int>>>> pq;
        
        
        vector<int> ans = {0, INT_MAX};
        
        
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
        }
        
        
        while (!pq.empty()) {
            
            int mini = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            if ((maxi - mini) < (ans[1] - ans[0])) {
                ans[0] = mini;
                ans[1] = maxi;
            }
            
            
            if (col < nums[row].size() - 1) {
                pq.push({nums[row][col + 1], {row, col + 1}});
                maxi = max(maxi, nums[row][col + 1]);
            } else {
                break;
            }
        }
        
        return ans;
    }
};
