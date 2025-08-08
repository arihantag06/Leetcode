class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1)return "";
        int l =0,r=n-1;
        bool f =false;
        while(l<n/2){
            if(palindrome[l]=='a'){
                l++;
            }
            else {
                palindrome[l] = 'a';
                f = true;
                break;
            }
        }
        if(!f)palindrome[n-1] = 'b';
        return palindrome;
    }
};