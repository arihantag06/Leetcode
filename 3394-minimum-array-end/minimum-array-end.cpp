class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long rem = n-1;
        long long pos=1;
        while(rem){
            if(!(x&pos)){
                result|=(rem&1)*pos;
                rem>>=1;
            }
            pos<<=1;
        }
        return result;
    }
};