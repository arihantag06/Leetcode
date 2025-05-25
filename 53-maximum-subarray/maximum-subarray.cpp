class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi = INT_MIN;
        int start =-1,ansStart=-1,ansEnd=-1;
        for(int i=0;i<nums.size();i++){
            if(sum==0)start=i;
            sum+=nums[i];
            if(sum>maxi) {
                maxi=sum;
                ansStart = start,ansEnd = i;
            }
            if(sum<0){
                sum =0;
            }
        }
        for(int i=ansStart;i<=ansEnd;i++){
            cout<<nums[i]<<" ";
        }
        return maxi;
    }
};