class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int cnt=0;
        int startIdx = -1;
        int n = s.size() , m = t.size();
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0,r=0;
        int mini=1e9;
        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<mini){
                    mini = r-l+1;
                    startIdx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        if(startIdx==-1)return "";

        return s.substr(startIdx,mini);


    }
};