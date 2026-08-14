class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        long long total = s;
        vector<long long> v;
        v.push_back(s);
        for (int a : arr) {
            long long cur = total + a;
            v.push_back(cur);
            total += cur;
            if (total > 2000000000000000000LL)
                total = 2000000000000000000LL;
        }
        long long need = x;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] <= need)
                need -= v[i];
            if (need == 0)
                return true;
        }
        return false;
    }
};