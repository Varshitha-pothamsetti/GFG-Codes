class Solution {
  public:
    string minWindow(string &s, string &p) {
        
        vector<int> freq(26,0);
        
        for(char c : p)
            freq[c - 'a']++;
        
        int left = 0;
        int count = p.size();
        int minLen = INT_MAX;
        int start = -1;
        
        for(int right = 0; right < s.size(); right++) {
            
            if(freq[s[right] - 'a'] > 0)
                count--;
            
            freq[s[right] - 'a']--;
            
            while(count == 0) {
                
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                
                freq[s[left] - 'a']++;
                
                if(freq[s[left] - 'a'] > 0)
                    count++;
                
                left++;
            }
        }
        
        if(start == -1)
            return "";
        
        return s.substr(start, minLen);
    }
};