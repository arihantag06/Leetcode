class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();int m = board[0].size();
        vector<vector<int>>vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int uld = 0;
                if(i>0 && j>0) uld = board[i-1][j-1];
                int urd = 0;
                if(i>0 && j<m-1) urd = board[i-1][j+1];
                int u = 0;
                if(i>0) u = board[i-1][j];
                int l = 0;
                if(j>0) l = board[i][j-1];
                int r = 0;
                if(j<m-1) r= board[i][j+1];
                int lld = 0;
                if(j>0 && i<n-1) lld = board[i+1][j-1];
                int lrd = 0;
                if(j<m-1 && i<n-1) lrd = board[i+1][j+1];
                int d = 0;
                if(i<n-1) d = board[i+1][j];

                int sum = uld+urd+u+l+r+lld+lrd+d;
                if (board[i][j] == 1) {  
                    if (sum < 2 || sum > 3) vec[i][j] = 0;  
                    else vec[i][j] = 1; 
                } else {  
                    if (sum == 3) vec[i][j] = 1;  
                }
            }
        }
        board = vec;
    }
};