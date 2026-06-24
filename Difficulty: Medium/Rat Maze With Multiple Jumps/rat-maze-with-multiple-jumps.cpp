class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& mat,
               vector<vector<int>>& path,
               vector<vector<int>>& dp, int n) {

        if (i >= n || j >= n || mat[i][j] == 0)
            return false;

        if (i == n - 1 && j == n - 1) {
            path[i][j] = 1;
            return true;
        }

        if (dp[i][j] == 0)
            return false;

        path[i][j] = 1;

        for (int k = 1; k <= mat[i][j]; k++) {

            if (j + k < n && solve(i, j + k, mat, path, dp, n))
                return true;

            if (i + k < n && solve(i + k, j, mat, path, dp, n))
                return true;
        }

        path[i][j] = 0;
        dp[i][j] = 0;
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> path(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, 1));

        if (solve(0, 0, mat, path, dp, n))
            return path;

        return {{-1}};
    }
};