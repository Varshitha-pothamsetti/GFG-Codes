class Solution {
public:
    int minimumStep(int n) {
        int steps = 0;

        while (n > 1) {
            if (n % 3 == 0) {
                n = n / 3;
            } else {
                n = n - 1;
            }
            steps++;
        }

        return steps;
    }
};
