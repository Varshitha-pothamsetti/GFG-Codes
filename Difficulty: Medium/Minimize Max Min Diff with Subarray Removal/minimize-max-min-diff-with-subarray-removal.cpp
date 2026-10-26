class Solution {
  public:
    int minDiff(int k, vector<int> &arr) {
        int n = arr.size();

        if (k == 0) {
            int mn = arr[0], mx = arr[0];

            for (int i = 1; i < n; i++) {
                mn = min(mn, arr[i]);
                mx = max(mx, arr[i]);
            }

            return mx - mn;
        }

        if (k == n) return 0;

        vector<int> pmin(n), pmax(n);
        vector<int> smin(n), smax(n);

        pmin[0] = pmax[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pmin[i] = min(pmin[i - 1], arr[i]);
            pmax[i] = max(pmax[i - 1], arr[i]);
        }

        smin[n - 1] = smax[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            smin[i] = min(smin[i + 1], arr[i]);
            smax[i] = max(smax[i + 1], arr[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n - k; i++) {
            int mn, mx;

            if (i == 0) {
                mn = smin[k];
                mx = smax[k];
            } else if (i + k == n) {
                mn = pmin[i - 1];
                mx = pmax[i - 1];
            } else {
                mn = min(pmin[i - 1], smin[i + k]);
                mx = max(pmax[i - 1], smax[i + k]);
            }

            ans = min(ans, mx - mn);
        }

        return ans;
    }
};
