class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        int lo = 0,hi =n;
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                v.push_back(lo++);
            }
            else{
                v.push_back(hi--);
            }
        }
        v.push_back(lo);
        return v;
    }
};