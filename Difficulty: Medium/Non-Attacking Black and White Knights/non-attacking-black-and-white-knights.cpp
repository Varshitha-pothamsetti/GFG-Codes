class Solution {
public:
    int numOfWays(int n, int m) {
        long long total = 1LL * n * m;
        
        long long attacking = 4LL * (
            1LL * (n - 1) * max(0, m - 2) +
            1LL * (n - 2) * max(0, m - 1)
        );
        
        return total * (total - 1) - attacking;
    }
};