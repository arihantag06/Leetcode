class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.length();
        for (int i = 0; i<n; i++) {
            if (!st.empty() && st.top().first == s[i]) {
                auto p = st.top();
                st.pop();
                if (p.second < k - 1)
                    st.push({p.first, p.second + 1});
            } else
                st.push({s[i], 1});
        }
        string ans;
        while (!st.empty()) {
            while (st.top().second--) {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};