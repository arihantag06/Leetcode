#define P pair<int,int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        set<int>marked;
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        
        long long score=0;
        while(!pq.empty()){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(marked.find(idx)!=marked.end())continue;
            score+=val;
            marked.insert(idx);
            if(idx-1>=0)marked.insert(idx-1);
            if(idx+1<n)marked.insert(idx+1);
        }
        return score;
    }

};