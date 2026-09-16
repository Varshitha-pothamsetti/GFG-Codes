class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int half = n / 2;
        int ans = 0;

        vector<int> b(arr.begin() + half, arr.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < half; i++) {
            long long x = arr[i];

            long long target;
            if (x >= 0) {
                target = x / 5;
            } else {
                target = (x - 4) / 5;
            }

            int count = upper_bound(b.begin(), b.end(), target) - b.begin();

            ans += count;
        }

        return ans;
    }
};