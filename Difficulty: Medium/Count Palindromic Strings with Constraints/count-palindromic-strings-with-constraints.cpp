class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        long long ans = 0, perm;

        for (int len = 1; len <= n; len++) {
            int half = (len + 1) / 2;
            perm = 1;

            for (int i = 0; i < half; i++)
                perm = (perm * (k - i)) % MOD;

            ans = (ans + perm) % MOD;
        }

        return ans;
    }
};