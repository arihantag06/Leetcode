class Solution {
public:
    bool parseBoolExpr(string expression) {
    stack<char> st;
    for (char c : expression) {
        if (c == ',') continue;
        if (c != ')') {
            st.push(c);
        } else {
            vector<char> exp;
            while (st.top() != '(') {
                exp.push_back(st.top());
                st.pop();
            }
            st.pop();
            char op = st.top();
            st.pop();
            bool res = (op == '&') ? true : (op == '|') ? false : true;
            for (char e : exp) {
                if (op == '&') res &= (e == 't');
                if (op == '|') res |= (e == 't');
                if (op == '!') res = (e == 'f');
            }
            st.push(res ? 't' : 'f');
        }
    }
    return st.top() == 't';
    }
};
