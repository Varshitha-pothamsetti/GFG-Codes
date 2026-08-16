class Solution {
  public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MAX;
        for (int mask = 1; mask < (1 << n); mask++) {
            int prod = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    prod *= arr[i];
            }
            ans = min(ans, prod);
        }
        return ans;
    }
};