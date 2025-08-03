class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long n =0,sum=0;
        while(sum<neededApples){
            sum+=12*n*n;
            n++;
        }
        return (n-1)*8;
    }
};
