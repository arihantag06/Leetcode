class Solution {
public:
    int solve(int l, int r, int k, string &s, vector<int>& hash) {
        if (l > r) return 0;

        vector<int> freq(26, 0);
        for (int i = l; i <= r; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = l; i <= r; i++) {
            if (freq[s[i] - 'a'] < k) {
                return max(solve(l, i - 1, k, s, hash), solve(i + 1, r, k, s, hash));
            }
        }

        return r - l + 1;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n < k) return 0;

        vector<int> hash(26, 0);
        // for (int i = 0; i < n; i++) {
        //     hash[s[i] - 'a']++;
        // }

        return solve(0, n - 1, k, s, hash);
    }
};
