class Solution {
public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        const long long MOD = 1000000007;

        int n = arr.size();
        vector<int> freq(n + 1, 0);

        for (int x : arr) {
            if (x <= n)
                freq[x]++;
        }

        vector<long long> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        long long ans = 0;
        long long ways = 1;

        for (int mex = 0; mex <= r; mex++) {

            if (mex > 0) {
                if (freq[mex - 1] == 0)
                    break;

                ways = (ways * (pow2[freq[mex - 1]] - 1 + MOD)) % MOD;
            }

            if (mex >= l) {
                long long remaining = 0;

                for (int i = mex + 1; i <= n; i++) {
                    remaining += freq[i];
                }

                long long extra = pow2[remaining];
                ans = (ans + ways * extra) % MOD;
            }
        }

        return ans;
    }
};
