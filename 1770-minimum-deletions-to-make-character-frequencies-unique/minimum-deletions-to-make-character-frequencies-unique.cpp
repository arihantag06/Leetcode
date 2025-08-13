class Solution {
public:
    int minDeletions(string s) {
        vector<int>hash(26,0);
        for(char c:s){
            hash[c-'a']++;
        }


        sort(hash.begin(),hash.end());
        int del=0;
        for(int i=24;i>=0;i--){
            if(hash[i]==0)break;

            if(hash[i]>=hash[i+1]){
                int curr =hash[i];
                int next = hash[i+1];

                hash[i] = max(0,next-1);
                del+= curr - hash[i];
            }
        }
        return del;
    }
};