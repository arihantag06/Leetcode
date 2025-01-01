class Solution {
public:
    int maxScore(string s) {
        int score=INT_MIN,ones=0,zeros=0,n=s.length();
        for(int i=0;i<n-1;i++){
            if(s[i]=='1')ones++;
            else zeros++;
            score = max(score,zeros-ones);
        }
        if(s[n-1]=='1')ones++;
        return score+ones;
    }
};