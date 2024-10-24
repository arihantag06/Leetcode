class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        int count = 0;
        vector<vector<bool>>dp(N,vector<bool>(N,false));
        for(int L = 1 ; L<=N ; L++){
            for(int i = 0 ; i+L-1<N ; i++){
                int j = i+L-1;

                if(i==j) dp[i][i]=true;

                else if(i+1==j) dp[i][j] = (s[i]==s[j]);

                else dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                
                if(dp[i][j]==true) count++;
                
            }
        }
        return count;  
    }
};