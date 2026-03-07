class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        
        vector<vector<int>>dp(n+1, vector<int>(x+1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= x; i++){
            for(int d = 1; d <= n; d++){
                for(int f = 1; f <= m; f++){
                    if(i >= f){
                        dp[d][i] += dp[d-1][i-f];
                    }
                }
            }
        }
        return dp[n][x];
    }
};