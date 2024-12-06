class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st(banned.begin(),banned.end());
        int s=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)!=st.end())continue;
            s+=i;
            if(s>maxSum)break;
            cnt++;
        }
        return cnt;
    }
};