class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        
        int add = 0;
        int mul = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            
            int cnt = 0;
            
            while (arr[i] > 0) {
                
                if (arr[i] % 2 == 1) {
                    add++;
                    arr[i]--;
                }
                else {
                    arr[i] /= 2;
                    cnt++;
                }
            }
            
            if (cnt > mul) {
                mul = cnt;
            }
        }
        
        return add + mul;
    }
};