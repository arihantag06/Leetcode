class Solution {
public:
    vector<char> vec = {'a', 'b', 'c'};
    
    void solve(string s, vector<string>& v, int n, char last) {
        if (s.size() == n) {
            v.push_back(s);
            return;
        }

        for (char c : vec) {
            if (c == last) continue;
            s.push_back(c);
            solve(s, v, n, c);
            s.pop_back();
        }
    }
    
    string getHappyString(int n, int k) {
        vector<string> v;
        solve("", v, n, ' ');  
        return k <= v.size() ? v[k - 1] : "";
    }
};
