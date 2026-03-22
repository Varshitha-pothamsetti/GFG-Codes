class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        
        int time = 0;
        
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int nr = r + drow[k];
                    int nc = c + dcol[k];
                    
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 1) {
                        mat[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            
            time++;
        }
        
        return (fresh == 0) ? time : -1;
    }
};