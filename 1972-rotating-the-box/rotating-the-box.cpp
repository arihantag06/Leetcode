class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        for(auto& row:box){
            int e=m-1;
            int s=m-1;
            while(s>=0){
                if(row[s]=='*'){
                    e = s-1;
                }
                else if(row[s]=='#'){
                    swap(row[s],row[e]);
                    e--;
                }
                s--; 
            }
        }
        
        vector<vector<char>>result(m,vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[j][n - i - 1] = box[i][j];
            }
        }
        
        return result;

    }
};