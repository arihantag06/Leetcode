class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        string temp = "";
        bool flag = false;
        for(auto &s:source){
            for(int i=0;i<s.length();i++){
                if(!flag && i<s.length()-1 && s[i]=='/' && s[i+1]=='/'){
                    break;
                }
                if(!flag && i<s.length()-1 && s[i]=='/' && s[i+1]=='*'){
                    /*
                    start of comment block
                    so flag is set to true
                    */
                    flag = true;
                    i++;
                    continue;
                }
                if(flag && i<s.length()-1 && s[i]=='*' && s[i+1]=='/'){
                    /*
                    end of the comment block
                    so flag is set to false
                    */
                    flag = false;
                    i++;
                    continue;
                }
                if(!flag){
                    temp.push_back(s[i]);
                }
            }
            if(!temp.empty() && !flag){
                result.push_back(temp);
                temp="";
            }
        }
        return result;

    }
};