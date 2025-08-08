class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for (int t : tasks) {
            mp[t]++;
        }

        int res = 0;
        for (auto& p : mp) {
            int cnt = p.second;
            if (cnt == 1) {
                return -1;  
            }
            if (cnt % 3 == 0) {
                res += cnt / 3;
            }
            else if (cnt % 3 == 1) {
                res += (cnt / 3 - 1) + 2;
            }
            else {  
                res += cnt / 3 + 1;
            }
        }
        return res;
    }
};
