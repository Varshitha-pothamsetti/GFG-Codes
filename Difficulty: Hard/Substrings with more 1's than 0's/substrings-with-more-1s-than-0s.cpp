class Solution {
public:
    int countSubstring(string& s) {
        int n = s.length();
        int totalSubstrings = 0;
        int balance = 0;
        
        vector<int> balanceCounts(2 * n + 1, 0);
        int offset = n;
        balanceCounts[0 + offset] = 1;
        
        int currentValidCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                currentValidCount += balanceCounts[balance + offset];
                balance++;
            } else {
                balance--;
                currentValidCount -= balanceCounts[balance + offset];
            }
            
            totalSubstrings += currentValidCount;
            balanceCounts[balance + offset]++;
        }
        
        return totalSubstrings;
    }
};