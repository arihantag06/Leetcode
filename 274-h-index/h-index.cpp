class Solution {
public:
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        int N = papers;
        sort(begin(citations),end(citations));
        int maxi = INT_MIN;
        while(papers){
            int idx = lower_bound(begin(citations),end(citations),papers)-begin(citations);
            int diff = N-idx;
            if(diff>=papers)maxi = max(maxi,papers);
            papers--;
        }
        return maxi==INT_MIN?0:maxi;
    }
};