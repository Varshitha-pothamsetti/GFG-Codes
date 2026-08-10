class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();
        
        int no = 0;
        int low = 0;
        int high = h[0];
        
        for (int i = 1; i < n; i++) {
            int newNo = max(no, max(low, high));
            int newLow = max(no, max(low, high)) + l[i];
            int newHigh = no + h[i];
            
            no = newNo;
            low = newLow;
            high = newHigh;
        }
        
        return max(no, max(low, high));
    }
};