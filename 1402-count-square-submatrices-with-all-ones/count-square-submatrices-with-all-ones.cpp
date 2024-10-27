class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int N = matrix.size(),M=matrix[0].size();
        vector<vector<int>>dp(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            dp[i][0] = matrix[i][0];
        }
        for(int j=0;j<M;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(matrix[i][j]==0)dp[i][j] = 0;
                else dp[i][j] = 1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }

        int count = 0;
        for(auto x:dp){
            for(auto y:x){
                count+=y;
            }
        }
        return count;
    }
};