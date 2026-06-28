class Solution {
public:
    int countStrings(int n, int k) {
        const int MOD = 1000000007;

        vector<vector<int>> dp0(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> dp1(n + 1, vector<int>(k + 1, 0));

        dp0[1][0] = 1;
        dp1[1][0] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp0[i][j] = ((long long)dp0[i - 1][j] + dp1[i - 1][j]) % MOD;

                dp1[i][j] = (dp1[i][j] + dp0[i - 1][j]) % MOD;

                if (j > 0) {
                    dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % MOD;
                }
            }
        }

        return ((long long)dp0[n][k] + dp1[n][k]) % MOD;
    }
};