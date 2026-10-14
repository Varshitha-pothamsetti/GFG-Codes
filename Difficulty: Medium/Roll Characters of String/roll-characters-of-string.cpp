class Solution {
public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.size();
        int m = roll.size();
        vector<int> diff(n + 1, 0);

        for (int x : roll) {
            diff[0]++;
            diff[x]--;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            count = (count + diff[i] + 26) % 26;
            s[i] = (s[i] - 'a' + count) % 26 + 'a';
        }

        return s;
    }
};