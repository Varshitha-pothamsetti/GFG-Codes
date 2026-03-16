/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int dfs(Node* root, long long currSum, int k, unordered_map<long long,int>& mp){
        if(!root) return 0;
        
        currSum += root->data;
        
        int count = 0;
        if(mp.count(currSum - k))
            count += mp[currSum - k];
        
        mp[currSum]++;
        
        count += dfs(root->left, currSum, k, mp);
        count += dfs(root->right, currSum, k, mp);
        
        mp[currSum]--;
        
        return count;
    }
    
    int countAllPaths(Node *root, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        return dfs(root, 0, k, mp);
    }
};