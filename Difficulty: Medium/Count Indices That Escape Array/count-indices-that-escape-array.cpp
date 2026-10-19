class Solution {
public:
    int goodIndices(vector<int> &arr) {
        int n = arr.size();
        vector<int> state(n, 0);
        // 0 = not visited, 1 = visiting, 2 = good, 3 = bad

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (state[i] != 0) continue;

            vector<int> path;
            int pos = i;

            while (pos >= 0 && pos < n && state[pos] == 0) {
                state[pos] = 1;
                path.push_back(pos);
                pos += arr[pos];
            }

            bool good;

            if (pos < 0 || pos >= n) {
                good = true;
            } else if (state[pos] == 1) {
                good = false;
            } else {
                good = (state[pos] == 2);
            }

            for (int j = (int)path.size() - 1; j >= 0; j--) {
                int idx = path[j];

                if (good) {
                    state[idx] = 2;
                    count++;
                } else {
                    state[idx] = 3;
                }
            }
        }

        return count;
    }
};
