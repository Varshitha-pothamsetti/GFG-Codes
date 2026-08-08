class Solution {
public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1)
            return -1;

        vector<int> parent(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        function<int(int)> find = [&](int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        };

        int extra = 0;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            int pu = find(u);
            int pv = find(v);

            if (pu == pv)
                extra++;
            else
                parent[pu] = pv;
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};