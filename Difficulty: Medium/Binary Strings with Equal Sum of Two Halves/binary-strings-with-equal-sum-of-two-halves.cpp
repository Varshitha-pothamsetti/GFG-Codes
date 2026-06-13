class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int computeValue(int n) {
        vector<long long> fact(2 * n + 1);

        fact[0] = 1;
        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long denom = (fact[n] * fact[n]) % MOD;
        long long ans = (fact[2 * n] * power(denom, MOD - 2)) % MOD;

        return (int)ans;
    }
};