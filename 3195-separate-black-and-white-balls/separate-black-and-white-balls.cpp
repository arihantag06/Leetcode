class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        long long count=0;
        int n = s.length();
       vector<long long>zeros(n,0);
       for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
        count++;
        }
        zeros[i] = max(zeros[i],count);
       }

       for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans+=zeros[i];
        }
       }
       return ans;
    }
};