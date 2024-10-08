class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int left = 0, right = s.size() - 1;
        int moves = 0;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                
                int k = right;
                while (k > left && s[k] != s[left]) {
                    k--;
                }


                if (k == left) {
                    
                    swap(s[left], s[left + 1]);
                    moves++;
                } else {
                    
                    while (k < right) {
                        swap(s[k], s[k + 1]);
                        k++;
                        moves++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return moves;
    }
};