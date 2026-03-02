class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        int water = 0;
        
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] >= leftmax)
                    leftmax = arr[left];
                else
                    water += leftmax - arr[left];
                left++;
            }
            else
            {
                if(arr[right] >= rightmax)
                  rightmax = arr[right];
                else
                   water += rightmax - arr[right];
                 right--;
            }
        }
        return water;
    }
};