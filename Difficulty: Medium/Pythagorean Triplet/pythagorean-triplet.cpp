class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++){
            arr[i] = arr[i] * arr[i];
            s.insert(arr[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(s.count(arr[i] + arr[j])){
                    return true;
                }
            }
        }

        return false;
    }
};