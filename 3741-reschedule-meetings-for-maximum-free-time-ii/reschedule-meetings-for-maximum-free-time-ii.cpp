class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n  = startTime.size();
        vector<int>pre(n+1,0),suf(n+1,0);

        int end = 0,ans = startTime[0];
        for(int i=0;i<n;i++){
            int gap = startTime[i]-end;
            ans = max(gap,ans);
            end = endTime[i];
            pre[i+1] = max(pre[i],gap);
        }

        ans = max(ans,eventTime-endTime[n-1]);

        int start = eventTime;
        for(int i=n-1;i>=0;i--){
            int gap = start-endTime[i];
            start = startTime[i];
            suf[i] = max(gap,suf[i+1]);
        }

        for(int i=0;i<n;i++){
            int prevend = (i==0?0:endTime[i-1]);
            int nextstart = (i==(n-1)?eventTime:startTime[i+1]);

            int gap = nextstart-prevend;
            int len = endTime[i] - startTime[i];
            if((pre[i]>=len) || (suf[i+1]>=len)){
                ans = max(ans,gap);
            }
            else{
                ans = max(ans,gap-len);
            }
        }
        return ans;
    }

};