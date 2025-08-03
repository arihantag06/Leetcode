class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }

        int cnt = 1;
        int prev = -1000000001; 
        vector<int> res(arr.size());

        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int val = t.first;
            int idx = t.second;

            if (val != prev) {
                res[idx] = cnt;
                prev = val;
                cnt++;
            } else {
                res[idx] = cnt - 1;
            }
        }
        return res;
    }
};
