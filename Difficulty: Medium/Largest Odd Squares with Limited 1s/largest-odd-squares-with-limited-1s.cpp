class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat,
                              vector<vector<int>>& queries,
                              int k) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pref[i + 1][j + 1] = mat[i][j]
                    + pref[i][j + 1]
                    + pref[i + 1][j]
                    - pref[i][j];
            }
        }

        vector<int> ans;

        for(auto q : queries) {
            int r = q[0];
            int c = q[1];

            int maxRadius = min(min(r, n - 1 - r),
                                min(c, m - 1 - c));

            int left = 0, right = maxRadius;
            int best = -1;

            while(left <= right) {
                int radius = (left + right) / 2;

                int r1 = r - radius;
                int c1 = c - radius;
                int r2 = r + radius;
                int c2 = c + radius;

                int ones = pref[r2 + 1][c2 + 1]
                         - pref[r1][c2 + 1]
                         - pref[r2 + 1][c1]
                         + pref[r1][c1];

                if(ones <= k) {
                    best = radius;
                    left = radius + 1;
                } else {
                    right = radius - 1;
                }
            }

            if(best == -1) {
                ans.push_back(-1);
            } else {
                ans.push_back(2 * best + 1);
            }
        }

        return ans;
    }
};