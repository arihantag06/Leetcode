class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto s:strs){
            string t = s;
            sort(begin(t),end(t));
            mp[t].push_back(s);
        }

        vector<vector<string>>res;
        for(auto x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};