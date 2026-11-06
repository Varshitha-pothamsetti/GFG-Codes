class Solution {
public:
    int countBT(int h) {
        long long mod = 1000000007;

        if (h == 0 || h == 1)
            return 1;

        long long a = 1, b = 1, c;

        for (int i = 2; i <= h; i++) {
            c = (b * b + 2 * b * a) % mod;
            a = b;
            b = c;
        }

        return b;
    }
};