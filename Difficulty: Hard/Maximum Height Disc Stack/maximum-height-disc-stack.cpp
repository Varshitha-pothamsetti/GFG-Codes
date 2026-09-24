class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({r[i], h[i]});
        }

        sort(a.begin(), a.end());

        vector<int> bit(1002, 0);

        auto query = [&](int x) {
            int ans = 0;
            while (x > 0) {
                ans = max(ans, bit[x]);
                x -= x & -x;
            }
            return ans;
        };

        auto update = [&](int x, int val) {
            while (x <= 1001) {
                bit[x] = max(bit[x], val);
                x += x & -x;
            }
        };

        int ans = 0;

        int i = 0;
        while (i < n) {
            int j = i;

            while (j < n && a[j].first == a[i].first)
                j++;

            vector<pair<int, int>> temp;

            for (int k = i; k < j; k++) {
                int height = a[k].second;
                int best = query(height - 1);
                temp.push_back({height, best + height});
                ans = max(ans, best + height);
            }

            for (auto p : temp)
                update(p.first, p.second);

            i = j;
        }

        return ans;
    }
};