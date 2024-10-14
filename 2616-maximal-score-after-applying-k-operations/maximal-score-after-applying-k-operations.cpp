class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq(begin(nums),end(nums));
        long long score=0;
        while(!pq.empty() && k>0){
            long long t = pq.top();
            pq.pop();
            while(t>=pq.top() && k>0){
                score+= t;
                if(t%3==0){
                    t = t/3;
                }
                else t = t/3+1;
                k--;
            }
            pq.push(t);
            
        }
        return score;
    }
};