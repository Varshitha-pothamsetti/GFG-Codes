class Solution {
public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            long long count = 0;

            for (int x : arr) {
                if (x & (1 << bit))
                    count++;
            }

            ans += count * (count - 1) / 2 * (1LL << bit);
        }

        return ans;
    }
};