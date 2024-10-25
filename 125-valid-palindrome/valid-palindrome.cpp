class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.length();
        int i=0,j=N-1;
        while (i <= j) {
        char start = tolower(s[i]);
        char end = tolower(s[j]);
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) {
            i++;
            continue;
        }
        if (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) {
            j--;
            continue;
        }
        if (start != end) {
            return false;
        }

        i++;
        j--;
    }
        return true;
    }
};