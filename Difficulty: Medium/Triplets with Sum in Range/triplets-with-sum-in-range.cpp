class Solution {
  public:
    long long count(vector<int>& arr, int x) {
        int n = arr.size();
        long long ans = 0;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                long long sum = arr[i] + arr[left] + arr[right];

                if (sum <= x) {
                    ans += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }

    int countTriplets(vector<int> &arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }
};