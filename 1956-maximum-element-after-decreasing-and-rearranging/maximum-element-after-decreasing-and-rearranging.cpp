class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=0){arr[0]=1;}
        int maxi =1;
        int n = arr.size();
        for(int i=1;i<n;i++){
            int diff = abs(arr[i]-arr[i-1]);
            if(diff>1){
                arr[i]= arr[i-1]+1;
            }
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
};