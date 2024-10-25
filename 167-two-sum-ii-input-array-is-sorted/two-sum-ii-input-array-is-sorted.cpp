class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;i++){
            int tar = target-numbers[i];
            int idx = lower_bound(begin(numbers),end(numbers),tar) - begin(numbers);
            int val = numbers[idx];
            if(idx<n && idx!=i && val==tar){
                vector<int>t = {i+1,idx+1};
                sort(t.begin(),t.end());
                return t;
            }
        }
        return {-1,-1};
    }
};