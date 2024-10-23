class Solution {
public:
    string longestWord(vector<string>& words) {
        
        sort(words.begin(), words.end());
        
        set<string> built; 
        string res;
        
       
        for (const string& word : words) {
            int len = word.size();
            if (len == 1 || built.count(word.substr(0, len - 1))) {
                built.insert(word);  
                if (word.size() > res.size()) {
                    res = word;
                }
            }
        }
        
        return res;
    }
};
