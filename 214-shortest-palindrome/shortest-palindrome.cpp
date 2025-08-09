class Solution {
public:
    vector<int> computeLPS(string p){
        int n = p.size();
        vector<int> lps(n,0);
        int prev = 0, i = 1;
        while(i<n){
            if(p[i]==p[prev]){
                lps[i++] = ++prev;
            } else if(prev==0){
                i++;
            } else {
                prev = lps[prev-1];
            }
        }
        return lps;
    }
    int kmp(string text,string pattern){
        vector<int> lps = computeLPS(pattern);
        for(auto x:lps)cout<<x<<" ";
        cout<<endl;
        int i = 0, j = 0;
        while(i < (int)text.size()){
            if(text[i] == pattern[j]) { i++; j++; }
            else if(j == 0) { i++; }
            else { j = lps[j-1]; }
        }
        return j; 
    }

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());        
        int L = kmp(rev, s);     
        return rev.substr(0, s.size() - L) + s; 
    }
};
