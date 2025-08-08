class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minitime=0;
        for(int i=0; i<colors.size(); i++ ){
            int maxi=0;
            while(colors[i]==colors[i+1]){
                minitime+=neededTime[i];
                maxi=max(maxi,neededTime[i]);
                i++;
            }
            minitime+=neededTime[i];
            maxi=max(maxi,neededTime[i]);
            minitime-=maxi;
        }
        return minitime;
    }
};