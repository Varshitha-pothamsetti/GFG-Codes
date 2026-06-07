class Solution {
public:
    string profession(int level, int pos) {
        int cnt = 0;
        int x = pos - 1;

        while (x) {
            cnt += (x & 1);
            x >>= 1;
        }

        return (cnt % 2 == 0) ? "Engineer" : "Doctor";
    }
};