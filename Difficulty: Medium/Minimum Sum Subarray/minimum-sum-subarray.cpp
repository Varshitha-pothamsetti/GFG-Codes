class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        int sum = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            sum = min(arr[i], sum + arr[i]);

            if (sum < ans)
                ans = sum;
        }

        return ans;
    }
};