class Solution {
public:
    int bs(vector<int>& prices, int x) {
        int low = 0, high = prices.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prices[mid] > x) high = mid - 1;
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> mp;

        
        for (auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            mp[price] = max(mp[price], beauty);
        }

        
        vector<int> prices;
        for (auto& it : mp) prices.push_back(it.first);
        sort(prices.begin(), prices.end());

        
        vector<int> maxBeautyUpToPrice(prices.size());
        maxBeautyUpToPrice[0] = mp[prices[0]];
        for (int i = 1; i < prices.size(); ++i) {
            maxBeautyUpToPrice[i] = max(maxBeautyUpToPrice[i - 1], mp[prices[i]]);
        }

        
        vector<int> result;
        for (int q : queries) {
            int idx = bs(prices, q);  
            if (idx != -1) {
                result.push_back(maxBeautyUpToPrice[idx]);
            } else {
                result.push_back(0); 
            }
        }
        return result;
    }
};
