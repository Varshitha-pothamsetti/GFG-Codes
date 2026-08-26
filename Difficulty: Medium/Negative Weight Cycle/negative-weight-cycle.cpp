class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<long long> dist(V, 0);
        for (int i = 0; i < V; i++) {
            bool updated = false;
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                    if (i == V - 1)
                        return true;
                }
            }
            if (!updated)
                return false;
        }
        return false;
    }
};