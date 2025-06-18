class Solution {
public:
    bool f(vector<int>&a,int k , int h){
        long long hrs = 0;
        for(int i=0;i<a.size();i++){
            hrs+=(a[i]+k-1)/k;
        }
        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end()),ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(f(piles,mid,h)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};