class Solution {
public:
    vector<vector<long long>>dp;
    long long f(int i, int j, vector<int>&robot,vector<int>&factories){
        if(i<0)return 0;
        if(j<0)return LLONG_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        long long exclude = f(i,j-1,robot,factories);
        long long next = f(i-1,j-1,robot,factories);
        long long include =LLONG_MAX;
        if(next!=LLONG_MAX) include = abs(robot[i]-factories[j])+next;
        return dp[i][j]= min(exclude,include);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>factories;
        for(auto x:factory){
            int pos = x[0];
            int lim = x[1];
            while(lim--){
                factories.push_back(pos);
            }
        }
        int n = robot.size();
        int m = factories.size();
        dp.resize(n,vector<long long>(m,-1));
        sort(begin(factories),end(factories));
        sort(begin(robot),end(robot));
        return f(robot.size()-1,factories.size()-1,robot,factories);
    }
};