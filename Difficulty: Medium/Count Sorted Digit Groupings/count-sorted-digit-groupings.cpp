class Solution {
public:
    long long dp[101][901];

    long long solve(int idx, int prevSum, string &s) {
        int n = s.size();

        if (idx == n)
            return 1;

        if (dp[idx][prevSum] != -1)
            return dp[idx][prevSum];

        long long ways = 0;
        int currSum = 0;

        for (int j = idx; j < n; j++) {
            currSum += (s[j] - '0');

            if (currSum >= prevSum) {
                ways += solve(j + 1, currSum, s);
            }
        }

        return dp[idx][prevSum] = ways;
    }

    int validGroups(string &s) {
        memset(dp, -1, sizeof(dp));
        return (int)solve(0, 0, s);
    }
};