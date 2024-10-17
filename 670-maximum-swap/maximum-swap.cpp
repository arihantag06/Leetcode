class Solution {
public:
    int maximumSwap(int num) {

        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(begin(digits), end(digits));

        int n = digits.size();

        vector<int> maxIdx(n);
        maxIdx[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            if (digits[i] > digits[maxIdx[i + 1]]) {
                maxIdx[i] = i;
            } else {
                maxIdx[i] = maxIdx[i + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (digits[i] < digits[maxIdx[i]]) {

                swap(digits[i], digits[maxIdx[i]]);
                break;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = ans * 10 + digits[i];
        }

        return ans;
    }
};
