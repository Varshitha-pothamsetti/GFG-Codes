class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> nextSmaller(n);
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty())
                nextSmaller[i] = n;
            else
                nextSmaller[i] = st.top();
            st.push(i);
        }
        int count = 0;
        
        for(int i = 0; i < n; i++){
            count += nextSmaller[i] - i;
        }
        return count;
    }
};