class Solution {
public:
    int partitionString(string s) {
        bool seen[26] = {false};
        int ans = 1; 
        for (char c : s) {
            if (seen[c - 'a']) {
                ans++;
                for (int i = 0; i < 26; i++) {
                    seen[i] = false;
                }
            }
            seen[c - 'a'] = true;
        }
        return ans;
    }
};
