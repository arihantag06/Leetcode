class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>hash;
        int n = nums.size();
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto it:hash){
            pq.push({it.second,it.first});
        }

        vector<int>result;
        for(int i=0;i<k;i++){
            int num = pq.top().second;
            pq.pop();
            result.push_back(num);
        }
        return result;
    }
};