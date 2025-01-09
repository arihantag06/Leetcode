class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int happinessScores[3][3] = {{0, 0, 0}, {0, -60, -10}, {0, -10, 40}};
    
        int powerOf3 = pow(3, n - 1);
      
        
        int memo[m * n][powerOf3 * 3][introvertsCount + 1][extrovertsCount + 1];
        memset(memo, -1, sizeof(memo)); 
      
        
        function<int(int, int, int, int)> dfs = [&](int position, int previousState, int ic, int ec) {
            
            if (position == m * n || (ic == 0 && ec == 0)) {
                return 0;
            }
            
            if (memo[position][previousState][ic][ec] != -1) {
                return memo[position][previousState][ic][ec];
            }
          
            int maxHappiness = 0;
            
            int up = previousState / powerOf3;
            int left = position % n == 0 ? 0 : previousState % 3; 
          
            
            for (int i = 0; i < 3; ++i) {
                
                if ((i == 1 && ic == 0) || (i == 2 && ec == 0)) {
                    continue;
                }
                
                int currentState = previousState % powerOf3 * 3 + i;
                
                int neighborHappiness = happinessScores[up][i] + happinessScores[left][i];
                
                int restHappiness = dfs(position + 1, currentState, ic - (i == 1), ec - (i == 2));
                
                int currentHappiness = i == 1 ? 120 : (i == 2 ? 40 : 0);
                
                maxHappiness = max(maxHappiness, neighborHappiness + restHappiness + currentHappiness);
            }
           
            return memo[position][previousState][ic][ec] = maxHappiness;
        };
      
       
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};