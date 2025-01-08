class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        int n = words.size();
        for(int i=0;i<n;i++){
            string s1 = words[i];
            int m = s1.length();
            for(int j=i+1;j<n;j++){
                string s2 = words[j];
                int p = s2.length();
                if(s2.substr(0,m)==s1  && s2.substr(p-m)==s1){
                    count++;
                }
            }
        }
        return count;
    }
};