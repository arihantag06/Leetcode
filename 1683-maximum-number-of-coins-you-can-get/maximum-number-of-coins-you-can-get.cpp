class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int i=0,j=piles.size()-1;
        int sum=0;
        while(i<=j){
            sum+=piles[j-1];
            j-=2;
            i++;
        }
        return sum;
    }
};