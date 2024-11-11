class Solution {
public:
    bool prime[1000];
    void seive() {
        fill(prime,prime+1000,true);
        prime[0]=false;
        prime[1]=false;
        for (int p = 2; p * p < 1000; p++) {
            if (prime[p]) {
                for (int i = p * p; i < 1000; i += p)
                    prime[i] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        seive();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]) continue;
            for(int p=2;p<nums[i];p++){
                if(!prime[p])continue;
                if(nums[i]-p<nums[i+1]){
                    nums[i]-=p;
                    break;
                }
            }

            if(nums[i]>=nums[i+1])return false;
            
        }
        return true;
    }
};
