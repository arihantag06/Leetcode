class Solution {
public:
    vector<int> computeLPS(string pattern){
    int n = pattern.size();
    int prevLPS = 0,i=1;
    vector<int>lps(n,0);
    while(i<n){
        if(pattern[i]==pattern[prevLPS]){
            lps[i] = prevLPS+1;
            i++;
            prevLPS++;
        }
        else if(prevLPS==0){
            lps[i] = 0;
            i++;
        }
        else {
            prevLPS= lps[prevLPS-1];
        }
    }
    return lps;
}

int f(string pattern, string text) {
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
       else {
        if(j==0){
            i++;
        }
        else {
            j = lps[j - 1];
        }
       }
       if(j==pattern.size()){
           return i-pattern.size();
       }
    }
    return -1;
}

    int strStr(string haystack, string needle) {
        return f(needle,haystack);
    }
};