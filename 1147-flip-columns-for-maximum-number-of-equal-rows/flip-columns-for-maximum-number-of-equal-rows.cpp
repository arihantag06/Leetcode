class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();


        int maxRows=0;

        for(auto& currRow:matrix){
            vector<int>inverted(m);
            for(int i=0;i<m;i++){
                inverted[i] = currRow[i]==0?1:0;
            }
            int count = 0;
            for(auto& row:matrix){
                if(row==currRow || row==inverted)count++;
            }
            maxRows= max(maxRows,count);
        }
        return maxRows;
    }
};