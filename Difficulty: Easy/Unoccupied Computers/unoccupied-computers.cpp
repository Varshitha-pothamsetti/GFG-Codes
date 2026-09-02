class Solution {
public:
    int solve(int n, string s) {
        int state[26] = {0};
        int computers = 0;
        int ans = 0;

        for (char c : s) {
            int x = c - 'A';

            if (state[x] == 0) {
                if (computers < n) {
                    state[x] = 1;
                    computers++;
                } else {
                    state[x] = 2;
                    ans++;
                }
            }
            else if (state[x] == 1) {
                state[x] = 0;
                computers--;
            }
        }

        return ans;
    }
};