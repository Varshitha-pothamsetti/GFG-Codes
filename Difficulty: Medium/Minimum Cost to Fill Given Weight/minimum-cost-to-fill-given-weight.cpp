class Solution {
public:
    int minimumCost(vector<int> &cost, int w) {
        const int INF = 1e9;

        vector<int> dp(w + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < cost.size(); i++) {
            if (cost[i] == -1) continue;

            int weight = i + 1;
            int price = cost[i];

            for (int j = weight; j <= w; j++) {
                dp[j] = min(dp[j], dp[j - weight] + price);
            }
        }

        return dp[w] == INF ? -1 : dp[w];
    }
};