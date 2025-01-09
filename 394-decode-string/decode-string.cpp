class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == ']') {
                string t = "";
                while (!st.empty() && st.top() != '[') {
                    t = st.top() + t;
                    st.pop();
                }
                
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }

                string number = "";
                while (!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }

                
                int num = stoi(number);
                string p = "";
                for (int i = 0; i < num; i++) {
                    p += t;
                }

                for (char c : p) {
                    st.push(c);
                }
            } else {
                st.push(s[i]);
            }
        }

        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
