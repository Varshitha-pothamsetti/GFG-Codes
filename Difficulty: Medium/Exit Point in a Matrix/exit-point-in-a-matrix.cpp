class Solution {
public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0, col = 0;
        int dir = 0; // 0=Right, 1=Down, 2=Left, 3=Up

        while (true) {
            if (mat[row][col] == 1) {
                dir = (dir + 1) % 4;
                mat[row][col] = 0;
            }

            if (dir == 0) col++;
            else if (dir == 1) row++;
            else if (dir == 2) col--;
            else row--;

            if (row < 0) {
                row++;
                break;
            }
            if (row >= n) {
                row--;
                break;
            }
            if (col < 0) {
                col++;
                break;
            }
            if (col >= m) {
                col--;
                break;
            }
        }

        return {row, col};
    }
};