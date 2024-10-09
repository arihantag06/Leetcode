class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>s1,s2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                s1.push(s[i]);
            }
            else {
                if(!s1.empty())s1.pop();
            }
        }

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')'){
                s2.push(s[i]);
            }
            else {
                if(!s2.empty())s2.pop();
            }
        }

        return s1.size()+s2.size();
    }
};