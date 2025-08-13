class Solution {
public:
    int minDeletions(string s) {
        vector<int>hash(26,0);
        for(char c:s){
            hash[c-'a']++;
        }
        int cnt=0;
        set<int>st;
        for(int x:hash){
            if(x!=0){
                if(st.find(x)==st.end()){
                    st.insert(x);
                } else {
                    while(st.find(x)!=st.end()){
                        x--;
                        cnt++;
                    }
                    if(x!=0)st.insert(x);
                }
            }
        }
        return cnt;
    }
};