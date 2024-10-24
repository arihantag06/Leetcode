class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v;
        string prev = "";

        for (auto& s : words) {
            string t = s;
            sort(t.begin(), t.end());  

            if (t != prev) {  
                v.push_back(s);  
                prev = t;  
            }
        }
        return v;
    }
};
