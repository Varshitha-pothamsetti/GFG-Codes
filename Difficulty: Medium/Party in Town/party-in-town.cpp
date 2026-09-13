class Solution {
public:
    pair<int, int> bfs(vector<vector<int>> &adj, int start) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        int farthest = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                v--;  // houses are numbered 1 to n

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (dist[v] > dist[farthest])
                        farthest = v;
                }
            }
        }

        return {farthest, dist[farthest]};
    }

    int partyHouse(vector<vector<int>> &adj) {
        // Find one end of the diameter
        auto p1 = bfs(adj, 0);

        // Find the other end and diameter length
        auto p2 = bfs(adj, p1.first);

        int diameter = p2.second;

        // Minimum maximum distance = radius
        return (diameter + 1) / 2;
    }
};