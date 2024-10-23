class Solution {
public:
    
    string longestWord(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        set<string>st;
        for(string s:words){
            st.insert(s);
        }

        vector<string>v;
        for(int i=0;i<n;i++){
            string word = words[i];
            bool f =true;
            int sz = word.length();
            string temp;
            for(int j=0;j<sz;j++){
                temp+=word[j];
                if(st.find(temp)==st.end()){
                    f=false;
                    break;
                }
            }
            if(f){
                v.push_back(word);
            }
        }
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        if(v.empty())return "";
        int maxLen = v[v.size()-1].length();
        string res = v[v.size()-1];
        for(int i=v.size()-2;i>=0;i--){
            int currLen = v[i].length();
            if(currLen==maxLen){
                if(v[i]<res) res = v[i];
            }
        }
        return res;
    }
};