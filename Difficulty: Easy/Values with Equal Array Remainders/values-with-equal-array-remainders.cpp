class Solution {
  public:
    int sameMod(vector<int> &arr) {
        int mn = arr[0], mx = arr[0];

        for (int x : arr) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        if (mn == mx)
            return -1;

        int g = 0;

        for (int x : arr) {
            g = gcd(g, x - mn);
        }

        int ans = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;
                if (i != g / i)
                    ans++;
            }
        }

        return ans;
    }
};