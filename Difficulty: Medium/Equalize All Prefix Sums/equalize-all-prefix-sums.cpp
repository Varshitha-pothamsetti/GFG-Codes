class Solution {
public:
    vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();

        vector<long long> pre(n);
        pre[0] = arr[0];

        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + arr[i];

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int m = i / 2;

            long long leftCost = 1LL * arr[m] * (m + 1) - pre[m];

            long long rightSum = pre[i] - pre[m];
            long long rightCost = rightSum - 1LL * arr[m] * (i - m);

            ans[i] = leftCost + rightCost;
        }

        return ans;
    }
};