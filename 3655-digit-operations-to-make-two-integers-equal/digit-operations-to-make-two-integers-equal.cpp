class Solution {
public:
    bool isPrime(int n){
        if(n<=1)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }

    int countDigit(int n){
        if(n==0)return 1;
        return floor(log10(n)+1);
    }
    int minOperations(int n, int m) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        if(isPrime(n)) return -1;
        
        unordered_set <int> s;
        pq.push({n, n});
        while(!pq.empty()){
            int num = pq.top().second;
            int ans = pq.top().first;
            pq.pop();
            if(num == m) return ans;
            if(s.find(num) != s.end()) continue;
            s.insert(num);

            int digits = countDigit(num);
            for(int i=0; i<digits; i++){
                int temp = num / pow(10, i);
                int d = temp % 10;

                if(d < 9){
                    int val = num + pow(10, i);
                    if(!isPrime(val) && s.find(val) == s.end()) pq.push({ans+val, val});
                }
                if(d > 0){
                    int val2 = num - pow(10, i);
                    if(!isPrime(val2) && s.find(val2) == s.end()) pq.push({ans+val2, val2});
                }
            }

        }
        return -1;
    }
};