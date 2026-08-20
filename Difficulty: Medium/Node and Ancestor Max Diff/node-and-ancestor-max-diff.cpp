/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int solve(Node* root, int &ans) {
        if (root == nullptr)
            return INT_MAX;
        
        if (root->left == nullptr && root->right == nullptr)
            return root->data;
        
        int leftMin = solve(root->left, ans);
        int rightMin = solve(root->right, ans);
        
        int mn = min(leftMin, rightMin);
        
        ans = max(ans, root->data - mn);
        
        return min(root->data, mn);
    }

    int maxDiff(Node* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};