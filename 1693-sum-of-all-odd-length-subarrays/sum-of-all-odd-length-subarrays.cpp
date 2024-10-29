class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int N = arr.size();
        int totSum=0;
        for(int i=0;i<N;i++){
            int sum = 0;
            for(int j=i;j<N;j++){
                sum+=arr[j];
                if((j-i+1)%2!=0)totSum+=sum;
            }
        }
        return totSum;
    }
};