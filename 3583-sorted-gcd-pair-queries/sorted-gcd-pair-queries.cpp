#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        vector<ll>gcdCount(50001,0);
        for(auto num:nums){
            for(int i=1;(i*i)<=num;i++){
                if(num%i==0){
                    ll a = i;
                    ll b = num/i;
                    if(a==b){
                        gcdCount[a]++;
                    }else{
                        gcdCount[a]++;
                        gcdCount[b]++;
                    }
                }
            }
        }

        for(int i=1;i<=50000;i++){
            ll value = gcdCount[i];
            gcdCount[i] = (value*1ll*(value-1))/2ll;
        }

        for(int i=50000;i>=0;i--){
            if(gcdCount[i]>0){
                for(int j=1;(j*j)<=i;j++){
                    if(i%j==0){
                        ll x = j;
                        ll y = i/j;
                        if(x==y && y!=i){
                            gcdCount[x]-=gcdCount[i];
                        }
                        else {
                            if(x!=i)
                            gcdCount[x]-=gcdCount[i];
                            if(y!=i)
                            gcdCount[y]-=gcdCount[i];
                        }

                    }
                }
            }
        }

        for(int i=1;i<=50000;i++){
            gcdCount[i] +=gcdCount[i-1];
        }

        vector<int>ans;
        for(ll i:queries){
            int index = lower_bound(begin(gcdCount),end(gcdCount),i+1) - gcdCount.begin();
            ans.push_back(index);
        }
        return ans;
    }
};