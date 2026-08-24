class Solution {
  public:
    int prefixStrings(int n) {
        const long long MOD = 1000000007;

        vector<long long> fact(2 * n + 1);
        fact[0] = 1;

        for (int i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        auto power = [&](long long a, long long b) {
            long long res = 1;
            while (b > 0) {
                if (b & 1)
                    res = (res * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        };

        long long ans = fact[2 * n];
        ans = (ans * power(fact[n], MOD - 2)) % MOD;
        ans = (ans * power(fact[n], MOD - 2)) % MOD;
        ans = (ans * power(n + 1, MOD - 2)) % MOD;

        return ans;
    }
};