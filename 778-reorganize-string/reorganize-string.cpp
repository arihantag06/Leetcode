class Solution {
public:
    string reorganizeString(string s) {
        vector<int>hash(26,0);
        int n = s.length();
        for(char c:s){
            hash[c-'a']++;
            if(hash[c-'a']>(n+1)/2)return "";
        }

        string result;
        priority_queue<pair<int , char>>pq;
        for(char c = 'a';c<='z';c++){
            if(hash[c-'a']>0){
                pq.push({hash[c-'a'],c});
            }
        }

        while(pq.size()>=2){
            auto p1 = pq.top();pq.pop();
            auto p2 = pq.top();pq.pop();
            result.push_back(p1.second);
            result.push_back(p2.second);
            p1.first--;p2.first--;
            if(p1.first>0){
                pq.push(p1);
            }
            if(p2.first>0){
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};