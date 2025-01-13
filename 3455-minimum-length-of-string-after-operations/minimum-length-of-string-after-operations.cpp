class Solution {
public:
    int minimumLength(string s) {
    vector<int> hash(26, 0);
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a']++;
    }
    
    int len = n;
    int mn = n;

    for (int i = 0; i < n; i++) {
        if (hash[s[i] - 'a'] >= 3) {
            len -= 2;
            mn = min(mn, len);
            hash[s[i] - 'a'] -= 2;
        }
    }

    return mn == n ? n : mn;
}









};