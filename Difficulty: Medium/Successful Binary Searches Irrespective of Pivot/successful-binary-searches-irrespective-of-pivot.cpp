
class Solution {
public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int leftMax = 0;
        vector<int> rightMin(n);

        rightMin[n - 1] = INT_MAX;

        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > leftMax && arr[i] < rightMin[i]) {
                count++;
            }
            leftMax = max(leftMax, arr[i]);
        }

        return count;
    }
};
