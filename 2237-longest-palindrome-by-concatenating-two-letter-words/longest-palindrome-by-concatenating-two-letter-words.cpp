class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> cnt;
        for (auto &w : words) 
            cnt[w]++;

        int ans = 0;
        bool usedCenter = false;

        for (auto &p : cnt) {
            const string &w = p.first;
            int c = p.second;
            string rev = {w[1], w[0]};

            if (w == rev) {
                ans += (c / 2) * 4;
                if (c % 2 == 1) usedCenter = true;
            }
            else if (w < rev) {
                if (cnt.count(rev)) {
                    ans += min(c, cnt[rev]) * 4;
                }
            }
        }
        if (usedCenter) ans += 2;
        return ans;
    }
};
