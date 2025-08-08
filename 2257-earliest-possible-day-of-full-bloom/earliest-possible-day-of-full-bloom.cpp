class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; ++i)
            v[i] = {growTime[i], plantTime[i]};
        sort(v.begin(), v.end(), greater<>());
        int curPlant = 0;   
        int ans = 0;        
        for (auto &pr : v) {
            curPlant += pr.second;              
            ans = max(ans, curPlant + pr.first); 
        }
        return ans;
    }
};
