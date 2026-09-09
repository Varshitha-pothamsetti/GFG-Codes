class Solution {
  public:
    int findMax(int n) {
        int ans = n;
        int maxSum = 0;
        int x = n;
        while (x) {
            maxSum += x % 10;
            x /= 10;
        }
        for (int p = 1; p <= n; p *= 10) {
            int y = (n / p) * p - 1;
            if (y >= 1) {
                int sum = 0, z = y;
                while (z) {
                    sum += z % 10;
                    z /= 10;
                }
                if (sum > maxSum) {
                    maxSum = sum;
                    ans = y;
                }
            }
        }
        return ans;
    }
};