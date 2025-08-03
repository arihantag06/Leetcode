class Solution {
public:
    
    long long val(long long x) {
        return 2 * x * (x + 1) * (2 * x + 1);
    }

    long long minimumPerimeter(long long neededApples) {
        long long low = 0, high = 1;
        while (val(high) < neededApples) high <<= 1;
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (val(mid) >= neededApples) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return 8 * ans;
    }
};
