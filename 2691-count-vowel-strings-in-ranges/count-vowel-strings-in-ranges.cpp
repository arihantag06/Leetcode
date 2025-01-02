class Solution {
public:
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    set<char> st = set<char>(v.begin(), v.end());

    bool isValid(string &s) {
        return st.count(s[0]) > 0 && st.count(s.back()) > 0;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n, 0);

        for (int i = 0; i < n; i++) {
            if (isValid(words[i])) {
                prefix[i] = 1;
            }
        }

        for (int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1];
        }

        vector<int> result;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int count = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};
