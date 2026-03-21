class Solution {
  public:
    
    // Function to compute Catalan numbers
    int catalan(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
    
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int left = 0, right = 0;

            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) left++;
                else if (arr[j] > arr[i]) right++;
            }

            result.push_back(catalan(left) * catalan(right));
        }

        return result;
    }
};