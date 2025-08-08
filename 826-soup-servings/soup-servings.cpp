class Solution {
    double dp[200][200];
public:
    double f(int a, int b){
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0)           return 1.0;
        if (b <= 0)           return 0.0;        
        double &res = dp[a][b];
        if (res >= 0)         return res;
        res = 0.25 * f(a - 4, b    )  
            + 0.25 * f(a - 3, b - 1)  
            + 0.25 * f(a - 2, b - 2)
            + 0.25 * f(a - 1, b - 3);
        return res;
    }

    double soupServings(int n) {
        if (n >= 4800) return 1.0;

        
        int m = (n + 24) / 25;

        memset(dp, -1, sizeof(dp));
        return f(m, m);
    }
};
