class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        // Sort by width asc, and if width equal, by height desc
        sort(env.begin(), env.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> res;
        for (auto& e : env) {
            int h = e[1];
            auto it = lower_bound(res.begin(), res.end(), h);
            if (it == res.end())
                res.push_back(h);
            else
                *it = h;
        }

        return res.size();
    }
};
