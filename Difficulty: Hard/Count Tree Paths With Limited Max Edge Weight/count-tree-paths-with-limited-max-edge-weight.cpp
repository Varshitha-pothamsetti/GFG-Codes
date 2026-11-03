class Solution {
public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, vector<int>& queries) {

        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        vector<pair<int, int>> q;

        for (int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> parent(n + 1), sz(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        vector<int> ans(queries.size(), 0);
        int j = 0;
        long long count = 0;

        for (auto &it : q) {
            int x = it.first;
            int idx = it.second;

            while (j < edges.size() && edges[j][2] <= x) {
                int u = find(edges[j][0]);
                int v = find(edges[j][1]);

                if (u != v) {
                    count += 1LL * sz[u] * sz[v];

                    if (sz[u] < sz[v])
                        swap(u, v);

                    parent[v] = u;
                    sz[u] += sz[v];
                }

                j++;
            }

            ans[idx] = count;
        }

        return ans;
    }
};
