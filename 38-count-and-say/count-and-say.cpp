class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string prev = countAndSay(n-1);
        int count = 1; string res="";int i;
        for(i=1;i<prev.length();i++){
            if(prev[i]==prev[i-1]){
                count++;
            }
            else{
                res+=('0'+count);
                res+=prev[i-1];
                count=1;
            }
        }
        res+=to_string(count);
        res+=prev[i-1];
        return res;
    }
};