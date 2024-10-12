class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>>pq;
        sort(begin(intervals),end(intervals));
        int count=0;
        for(auto i:intervals){
            if(!pq.empty() && pq.top()<i[0]){
                pq.pop();
            }
            pq.push(i[1]);
            count = max(count,(int)pq.size());
        }
        return count;

    }
};