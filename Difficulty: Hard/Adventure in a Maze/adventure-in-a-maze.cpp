class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1000000007;

        vector<vector<long long>> ways(n, vector<long long>(n, 0));
        vector<vector<long long>> best(n, vector<long long>(n, 0));

        ways[0][0] = 1;
        best[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                if (j > 0 && grid[i][j - 1] != 2 && ways[i][j - 1] > 0) {
                    ways[i][j] =
                        (ways[i][j] + ways[i][j - 1]) % MOD;

                    best[i][j] = max(best[i][j],
                                     best[i][j - 1] + grid[i][j]);
                }

                if (i > 0 && grid[i - 1][j] != 1 && ways[i - 1][j] > 0) {
                    ways[i][j] =
                        (ways[i][j] + ways[i - 1][j]) % MOD;

                    best[i][j] = max(best[i][j],
                                     best[i - 1][j] + grid[i][j]);
                }
            }
        }

        if (ways[n - 1][n - 1] == 0)
            return {0, 0};

        return {
            (int)ways[n - 1][n - 1],
            (int)best[n - 1][n - 1]
        };
    }
};