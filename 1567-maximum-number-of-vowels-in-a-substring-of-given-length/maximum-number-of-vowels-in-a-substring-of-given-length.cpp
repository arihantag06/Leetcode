class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0, vowels = 0, n = s.size();

        for (int i = 0; i < k; i++) {
            if (st.count(s[i])) cnt++;
        }
        vowels = cnt;

        for (int i = k; i < n; i++) {
            if (st.count(s[i])) cnt++;
            if (st.count(s[i - k])) cnt--;
            vowels = max(vowels, cnt);
        }
        return vowels;
    }
};
