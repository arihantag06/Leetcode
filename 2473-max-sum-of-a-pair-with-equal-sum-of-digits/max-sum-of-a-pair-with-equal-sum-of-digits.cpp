class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        sort(nums.rbegin(),nums.rend());
        for(auto it:nums){
            int number = it;
            int sum = 0;
            while(number>0){
                sum+=number%10;
                number = number/10;
            }
            mp[sum].push_back(it);
        }


        int maxSum = -1;
        for(auto it:mp){
            vector<int> t = it.second;
            
            cout<<it.first<<" ";
            for(auto x:t){
                cout<<x<<" ";
            }
            cout<<endl;
            if(t.size()>=2)maxSum = max(maxSum , t[0]+t[1]);
        }
        return maxSum;
    }
};