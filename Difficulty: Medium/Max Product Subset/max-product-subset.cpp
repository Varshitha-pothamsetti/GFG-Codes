class Solution {
public:
    int findMaxProduct(vector<int>& arr) {
        const long long MOD = 1000000007;

        int n = arr.size();

        if (n == 1)
            return arr[0];

        int negCount = 0, zeroCount = 0;
        int maxNeg = INT_MIN;

        for (int x : arr) {
            if (x == 0)
                zeroCount++;
            else if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x);
            }
        }

        if (zeroCount == n)
            return 0;

        if (negCount == 1 && negCount + zeroCount == n)
            return 0;

        long long ans = 1;

        bool removed = false;

        for (int x : arr) {
            if (x == 0)
                continue;

            if ((negCount & 1) && x == maxNeg && !removed) {
                removed = true;
                continue;
            }

            ans = (ans * ((x % MOD + MOD) % MOD)) % MOD;
        }

        return (int)ans;
    }
};