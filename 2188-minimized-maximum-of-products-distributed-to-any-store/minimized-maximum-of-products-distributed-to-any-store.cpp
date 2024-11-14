class Solution {
public:
    bool isPos(vector<int>&quantities , int product , int stores){
        int totalStores = 0;
        for (int q : quantities) {
            totalStores += (q + product - 1) / product;
            if (totalStores > stores) return false; 
        }
        return totalStores <= stores;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(begin(quantities),end(quantities));
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPos(quantities,mid,n)){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};