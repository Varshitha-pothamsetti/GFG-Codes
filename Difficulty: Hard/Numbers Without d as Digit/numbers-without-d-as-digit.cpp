class Solution {
  public:
    int countWithout(int n, int d) {
        if (n == 0) return 0;

        string s = to_string(n);
        int dp[11][2][2] = {};

        dp[0][1][0] = 1;

        for (int i = 0; i < s.size(); i++) {
            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {
                    int cur = dp[i][tight][started];

                    if (cur == 0)
                        continue;

                    int limit = tight ? s[i] - '0' : 9;

                    for (int x = 0; x <= limit; x++) {
                        int nstarted = started || x != 0;

                        if (nstarted && x == d)
                            continue;

                        int ntight = tight && (x == s[i] - '0');

                        dp[i + 1][ntight][nstarted] += cur;
                    }
                }
            }
        }

        return dp[s.size()][0][1] + dp[s.size()][1][1];
    }
};