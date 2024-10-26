class Solution {
public:
    int possibleStringCount(string word) {
        set<char>st;
        int count=0;
        for(char c:word){
            if(st.find(c)!=st.end()){
                count++;
            }
            else {
                st.clear();
                st.insert(c);
            }
        }
        return count+1;
    }
};