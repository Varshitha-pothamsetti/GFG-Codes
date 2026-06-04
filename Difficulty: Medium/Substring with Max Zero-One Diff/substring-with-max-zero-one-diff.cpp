class Solution {
public:
    int maxSubstring(string &s) {
        int curr = 0;
        int maxi = INT_MIN;

        for (char ch : s) {
            int val = (ch == '0') ? 1 : -1;

            curr = max(val, curr + val);
            maxi = max(maxi, curr);
        }

        return (maxi < 0) ? -1 : maxi;
    }
};