class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> st;

        for (int num : arr) {
            int need = target - num;

            if (st.find(need) != st.end()) {
                return true;
            }

            st.insert(num);
        }

        return false;
    }
};