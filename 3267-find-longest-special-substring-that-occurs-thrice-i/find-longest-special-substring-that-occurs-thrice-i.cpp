class Solution {
public:
    bool isTrue(int mid , string s ,unordered_map<char , vector<int>> mp ){
        int count = 0;
        for(auto [key,values]:mp){
            count = 0;
            for(auto val: values){
                count+=max(0,val-mid+1);
            }
            if(count>=3) return true;
        }
        return false;
    }
    int maximumLength(string s) {
        unordered_map<char , vector<int>> mp;
        int count = 1;
        int lastchar = s[0];
        for(int i = 1;i<s.size();i++){
            if(s[i]==lastchar){
                count++;
            }
            else{
                mp[lastchar].push_back(count);
                lastchar = s[i];
                count = 1;
            }
        }

        mp[lastchar].push_back(count);


        // binary search for finding the correct ans

        int ans = -1;
        int l = 1  , r = s.size()-2;
        while(l<=r){
            int mid = (l+r)/2;
            if(isTrue(mid,s,mp)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;


    }
};