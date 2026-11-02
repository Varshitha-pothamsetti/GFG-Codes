class Solution {
public:
    int largestSumCycle(vector<int>& edge) {
        int n = edge.size();
        vector<int> vis(n, 0);
        int ans = -1;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 1)
                continue;

            unordered_map<int, int> mp;
            int curr = i;
            int sum = 0;

            while(curr != -1 && vis[curr] == 0) {
                vis[curr] = 1;
                mp[curr] = sum;
                sum += curr;
                curr = edge[curr];
            }

            if(curr != -1 && mp.find(curr) != mp.end()) {
                int cycleSum = 0;
                int node = curr;

                do {
                    cycleSum += node;
                    node = edge[node];
                } while(node != curr);

                ans = max(ans, cycleSum);
            }
        }

        return ans;
    }
};
