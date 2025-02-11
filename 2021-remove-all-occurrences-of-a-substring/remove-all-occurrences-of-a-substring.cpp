class Solution {
public:
    string removeOccurrences(string s, string part) {
        int m = part.length();
        
        while (true) {
            string temp = "";
            int prevInd = 0;
            bool found = false;
            
            for (int i = 0; i <= (int)s.length() - m; i++) {
                if (s.substr(i, m) == part) {
                    temp = s.substr(0, i) + s.substr(i + m); 
                    s = temp;  
                    found = true;
                    break; 
                }
            }
            
            if (!found) break;
        }
        
        return s;
    }
};
