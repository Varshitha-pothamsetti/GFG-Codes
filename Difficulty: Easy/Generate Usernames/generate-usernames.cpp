class Solution {
public:
    vector<string> generateUsernames(vector<string> arr) {
        unordered_set<string> reserved;
        unordered_set<string> used;
        unordered_map<string, int> cnt;

        for (string s : arr) {
            reserved.insert(s);
        }

        vector<string> ans;

        for (string s : arr) {
            if (used.find(s) == used.end()) {
                ans.push_back(s);
                used.insert(s);
            }
            else {
                int i = cnt[s] + 1;
                string temp = s + to_string(i);

                while (reserved.find(temp) != reserved.end() ||
                       used.find(temp) != used.end()) {
                    i++;
                    temp = s + to_string(i);
                }

                ans.push_back(temp);
                used.insert(temp);
                cnt[s] = i;
            }
        }

        return ans;
    }
};