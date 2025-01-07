class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> st(words.begin(), words.end());  
        set<string> result;  
        for(string s : words) {
            int n = s.length();
            for(int i = 0; i < n; i++) {
                for(int len = 1; len <= n-i; len++) {
                    string sub = s.substr(i, len);
                    if(st.find(sub) != st.end() && sub != s) {
                        result.insert(sub);
                    }
                }
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
};