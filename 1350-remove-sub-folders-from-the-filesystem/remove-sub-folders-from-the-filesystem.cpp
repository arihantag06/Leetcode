class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  
        set<string> st;
        vector<string> result;

        for (auto &s : folder) {
            string temp;
            bool isSubfolder = false;
            for (char c : s) {
                temp += c;
                if (c == '/' && st.find(temp) != st.end()) {
                    isSubfolder = true;
                    break;
                }
            }
            if (!isSubfolder) {
                result.push_back(s);
                st.insert(s + "/");
            }
        }
        return result;
    }
};
