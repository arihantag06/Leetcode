class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>v(24,0);
        for(int i=0;i<24;i++){
            for(int j=0;j<candidates.size();j++){
                if(candidates[j]&(1<<i)){
                    v[i]++;
                }
            }
        }

        return *max_element(begin(v),end(v));
    }
};