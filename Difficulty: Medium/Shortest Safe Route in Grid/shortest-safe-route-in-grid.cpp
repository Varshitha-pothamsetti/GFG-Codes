class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> unsafe(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    unsafe[i][j] = 1;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                            unsafe[ni][nj] = 1;
                    }
                }
            }
        }

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (!unsafe[i][0]) {
                q.push({{i, 0}, 1});
                visited[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.first.first;
            int y = cur.first.second;
            int steps = cur.second;

            if (y == m - 1)
                return steps;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    !unsafe[nx][ny] &&
                    !visited[nx][ny]) {

                    visited[nx][ny] = 1;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
    }
};