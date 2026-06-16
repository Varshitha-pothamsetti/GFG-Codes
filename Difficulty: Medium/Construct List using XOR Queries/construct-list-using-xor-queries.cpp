class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        vector<int> ans;
        int xr = 0;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int x = queries[i][1];

            if (type == 1) {
                xr ^= x;
            } else {
                ans.push_back(x ^ xr);
            }
        }

        ans.push_back(xr);

        sort(ans.begin(), ans.end());
        return ans;
    }
};