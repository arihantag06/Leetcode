class Solution {
public:
    int solve(int idx , string s,set<string>&st){
        if(idx>=s.length()) return 0;
        int maxi = 0;

        for(int i=idx+1;i<=s.length();i++){
            string t = s.substr(idx,i-idx);

            if(st.find(t)==st.end()){
                st.insert(t);

                maxi = max(maxi,1+solve(i,s,st));

                st.erase(t);
            }
        }
        return maxi;

    }
    int maxUniqueSplit(string s) {
        set<string>st;
        return solve(0,s,st);
        
    }
};