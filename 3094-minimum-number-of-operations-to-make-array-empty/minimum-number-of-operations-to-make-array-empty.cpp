class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>hash;
        for(int i:nums){
            hash[i]++;
        }
        int ans = 0;
        for(auto it:hash){
            int freq = it.second;
            if(freq<2)return -1;
            if(freq%3==0){
                ans+= freq/3;
            }
            else {
                int rem = freq%3;
                ans+=freq/3;
                if(rem%2==0){
                    ans+=rem/2;
                }
                else{
                    ans+=rem;
                }
            }
        }
        return ans;
    }
};