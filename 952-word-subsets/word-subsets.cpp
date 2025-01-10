class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>hash(26,0);

        for (auto& s : words2) {
            vector<int> temp(26, 0);
            for (char c : s) {
                temp[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                hash[i] = max(hash[i], temp[i]);
            }
        }

        vector<string>result;
        for(auto s:words1){
            vector<int>freq(26,0);
            bool flag =true;
            for(char c:s){
                freq[c-'a']++;
            }

            for(int i=0;i<26;i++){
                if(freq[i]<hash[i]){
                    flag = false;
                    break;
                }
            }

            if(flag)result.push_back(s);  
        }
        return result;
    }
};