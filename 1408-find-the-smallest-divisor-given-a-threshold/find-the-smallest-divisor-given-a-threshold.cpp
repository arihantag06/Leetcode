class Solution {
public:
    bool f(vector<int>&a,int div, int req){
        int sum = 0;
        for(int i=0;i<a.size();i++){
            sum+= (a[i]+div-1)/div;
        }
        return sum<=req;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), low = 1, high= *max_element(begin(nums),end(nums)),ans=1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(f(nums,mid,threshold)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};