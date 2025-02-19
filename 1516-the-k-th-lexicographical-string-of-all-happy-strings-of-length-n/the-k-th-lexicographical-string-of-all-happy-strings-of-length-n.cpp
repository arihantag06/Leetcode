class Solution {
public:
    vector<char> vec = {'a', 'b', 'c'};
    int count=0;
    void solve(string s, int n, char last,string&op,int k) {
        if (s.size() == n) {
            count++;
            if(count==k)op=s;
            return;
        }
        for (char c : vec) {
            if (c == last) continue;
            s.push_back(c);
            solve(s, n, c,op,k);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string  op;
        solve("", n, ' ',op,k);  
        return op;
    }
};
