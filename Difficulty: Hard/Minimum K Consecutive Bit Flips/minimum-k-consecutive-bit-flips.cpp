class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> flipStart(n, 0);
        
        int flip = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(i >= k)
                flip ^= flipStart[i - k];

            if((arr[i] ^ flip) == 0) {

                if(i + k > n)
                    return -1;

                ans++;
                flip ^= 1;
                flipStart[i] = 1;
            }
        }

        return ans;
    }
};