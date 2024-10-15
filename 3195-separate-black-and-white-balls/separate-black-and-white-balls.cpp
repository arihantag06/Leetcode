class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long count = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; i--) {
            if(s[i]=='0'){
                count++;
            }
            else if(s[i]=='1'){
                ans+=count;
            }
        }
        return ans;
    }
};