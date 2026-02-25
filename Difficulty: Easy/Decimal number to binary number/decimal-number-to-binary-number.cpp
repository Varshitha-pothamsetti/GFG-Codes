class Solution {
  public:
    void toBinary(string N) {
        
        int num = stoi(N);
        
        if(num == 0) {
            cout << 0;
            return;
        }
        
        string result = "";
        
        while(num > 0) {
            result += (num % 2) + '0';
            num /= 2;
        }
        
        reverse(result.begin(), result.end());
        
        cout << result;
    }
};