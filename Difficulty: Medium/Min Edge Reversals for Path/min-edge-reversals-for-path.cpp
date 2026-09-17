class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n + 1, INT_MAX);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for (auto it : adj[u]) {
                int v = it.first;
                int cost = it.second;

                if (dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;

                    if (cost == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};