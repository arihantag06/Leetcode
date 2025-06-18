class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>result;
        sort(begin(nums),end(nums));
        vector<int>temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
            if(temp.size()==3){
                result.push_back(temp);
                if(temp[2]-temp[0] >k) return {};
                temp.clear();
            }
        }
        return result;


    }
};