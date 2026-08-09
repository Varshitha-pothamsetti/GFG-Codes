class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> dp(n);
        for (int j = 0; j < n; j++)
            dp[j] = mat[0][j];
        for (int i = 1; i < n; i++) {
            vector<int> next(n, 0);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k)
                        next[j] = max(next[j], dp[k] + mat[i][j]);
                }
            }
            dp = next;
        }
        return *max_element(dp.begin(), dp.end());
    }
};