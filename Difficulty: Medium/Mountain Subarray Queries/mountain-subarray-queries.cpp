class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        
        vector<int> incEnd(n), decEnd(n);
        incEnd[n - 1] = decEnd[n - 1] = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                incEnd[i] = incEnd[i + 1];
            else
                incEnd[i] = i;
                
            if (arr[i] >= arr[i + 1])
                decEnd[i] = decEnd[i + 1];
            else
                decEnd[i] = i;
        }
        
        vector<bool> ans;
        
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            
            if (incEnd[l] >= r)
                ans.push_back(true);
            else
                ans.push_back(decEnd[incEnd[l]] >= r);
        }
        
        return ans;
    }
};