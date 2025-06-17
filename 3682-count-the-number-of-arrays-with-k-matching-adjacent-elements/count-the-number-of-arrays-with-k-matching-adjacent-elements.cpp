class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    long long fact(int num) {
        long long res = 1;
        for (int i = 2; i <= num; ++i)
            res = (res * i) % MOD;
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        if (k > n - 1) return 0;
        long long N_1 = fact(n - 1);
        long long K_ = fact(k);
        long long N_1_k = fact(n - k - 1);
        long long denom = (K_ * N_1_k) % MOD;
        long long result = (m * N_1) % MOD;
        result = (result * modpow(denom, MOD - 2)) % MOD;
        result = (result * modpow(m - 1, n - k - 1)) % MOD;
        return result;
    }
};
