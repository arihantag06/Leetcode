class Solution {
public:
    double dp[26][26][101];
    double solve(int row, int col, int n, int k){
        if(row<0 || row>=n || col<0 || col>=n)return 0;
        if(k==0)return 1;
        if(dp[row][col][k]!=-1)return dp[row][col][k];
        
        double sum=0;
        sum+= solve(row-2,col-1,n,k-1)/8.0;
        sum+= solve(row-2,col+1,n,k-1)/8.0;
        sum+= solve(row-1,col-2,n,k-1)/8.0;
        sum+= solve(row-1,col+2,n,k-1)/8.0;
        sum+= solve(row+1,col-2,n,k-1)/8.0;
        sum+= solve(row+1,col+2,n,k-1)/8.0;
        sum+= solve(row+2,col-1,n,k-1)/8.0;
        sum+= solve(row+2,col+1,n,k-1)/8.0;
        return dp[row][col][k] = sum;
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<=k;l++){
                    dp[i][j][l]=-1.0;
                }
            }
        }
        return solve(row,column,n,k);
    }
};