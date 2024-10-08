class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(begin(nums),end(nums));
      int n=nums.size();
      int closestSum=100000;
      for(int i=0;i<n-2;i++){
        int j=i+1,k=n-1;
      while(j<k){  
        int sum = nums[i]+nums[j]+nums[k];
        if(abs(target-sum)<abs(target-closestSum)){
            closestSum = sum;
        }
        if(sum>target)k--;
        else j++;
      }
    }
      return closestSum;
    }
};