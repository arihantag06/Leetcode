class Solution {
public:
    string compressedString(string word) {
        char temp = word[0];
        int count=1;
        string result;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1] && count<9){
                count++;
            }
            else {
                result+=to_string(count)+temp;
                temp = word[i];
                count = 1;
            }
        }
        result+=to_string(count)+temp;
        return result;

    }
};