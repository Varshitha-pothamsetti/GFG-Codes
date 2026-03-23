class Solution {
  public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj(V, -1);
        for (auto &e : edges) {
            adj[e[0]] = e[1];
        }

        vector<int> vis(V, 0);
        int ans = -1;

        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;

            unordered_map<int, int> stepMap;
            int node = i;
            int step = 0;

            while (node != -1 && !vis[node]) {
                vis[node] = 1;
                stepMap[node] = step++;
                node = adj[node];
            }

            if (node != -1 && stepMap.count(node)) {
                ans = max(ans, step - stepMap[node]);
            }
        }

        return ans;
    }
};