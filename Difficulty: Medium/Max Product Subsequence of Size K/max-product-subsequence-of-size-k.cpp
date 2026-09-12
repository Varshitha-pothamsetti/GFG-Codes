class Solution {
public:
    long long maxProduct(vector<int>& arr, int k) {
        const long long INF = 1e18;

        vector<long long> mx(k + 1, -INF);
        vector<long long> mn(k + 1, INF);

        mx[0] = mn[0] = 1;

        for (int x : arr) {
            for (int j = k; j >= 1; j--) {
                if (mx[j - 1] != -INF) {
                    long long a = mx[j - 1] * x;
                    long long b = mn[j - 1] * x;

                    mx[j] = max(mx[j], max(a, b));
                    mn[j] = min(mn[j], min(a, b));
                }
            }
        }

        return mx[k];
    }
};