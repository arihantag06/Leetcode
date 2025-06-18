class Solution {
public:
    bool f(vector<int>& a, int days, int m, int k) {
        int count = 0, bouquets = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] <= days) {
                count++;
                if(count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& a, int m, int k) {
        if(1LL * m * k > a.size()) return -1;
        int low = 1, high = *max_element(a.begin(), a.end()), ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(f(a, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
