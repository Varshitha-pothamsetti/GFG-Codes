/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // Base case
        if(root == NULL) {
            return 0;
        }
        
        // Count current node + left subtree + right subtree
        return 1 + getSize(root->left) + getSize(root->right);
    }
};