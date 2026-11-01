class Solution {
public:
    int maximumSubarray(vector<int>& arr) {
        int n = arr.size();

        int noSquare = arr[0];
        int square = arr[0] * arr[0];

        int ans = square;

        for (int i = 1; i < n; i++) {
            int x = arr[i];

            int newSquare = max({
                x * x,
                noSquare + x * x,
                square + x
            });

            int newNoSquare = max(x, noSquare + x);

            square = newSquare;
            noSquare = newNoSquare;

            ans = max(ans, max(square, noSquare));
        }

        return ans;
    }
};
