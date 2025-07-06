class Solution {
public:
    long long helper(string s , int sign , int idx, long long res){
        if(sign*res>=INT_MAX) return INT_MAX;

        if(sign*res<=INT_MIN) return INT_MIN;

        if(s[idx]==' ' || !isdigit(s[idx])) return res*sign;

        int sol = s[idx]-'0';
        return helper(s,sign,idx+1,res*10+sol);
    }
    int myAtoi(string s) {
        int f = 0;
        int sign=1;
        int i=0;
        while(i<s.size() && s[i]==' ')i++;

        if(s[i]=='-'){
            sign = -1;
            i++;
            f++;
        }
        if(s[i]=='+'){
            sign=1;
            i++;
            f++;
        }
        if(f>1) return 0;
        return helper(s,sign,i,0);
    }
};