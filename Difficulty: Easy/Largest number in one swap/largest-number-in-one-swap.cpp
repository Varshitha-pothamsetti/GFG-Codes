class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            char max_char = *max_element(s.begin() + i, s.end());
            if (s[i] < max_char) {
                int max_idx = s.find_last_of(max_char);
                swap(s[i], s[max_idx]);
                return s;
            }
        }
        return s;
    }
};