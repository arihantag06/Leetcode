class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,minlen=1e9,n=s.size(),m=t.size(),cnt=0 ,startIndex=-1;
        int hash[256] = {0};
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    startIndex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        if(startIndex==-1)return "";
        return s.substr(startIndex,minlen);

    }
};