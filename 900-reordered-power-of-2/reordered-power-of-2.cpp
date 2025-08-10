class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string t = to_string(n);
        int p = log(1e9)/log(2);
        cout<<p<<endl;
        sort(t.begin(),t.end());
        for(int i=0;i<30;i++){
            string s = to_string(1<<i);
            sort(s.begin(),s.end());
            if(s==t)return true;
        }
        return false;
    }
};