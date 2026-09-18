/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/
class Solution {
  public:
    int absDiff(Node *root) {
        vector<int> v;

        function<void(Node*)> inorder = [&](Node* root) {
            if (root == NULL) return;

            inorder(root->left);
            v.push_back(root->data);
            inorder(root->right);
        };

        inorder(root);

        sort(v.begin(), v.end());

        int ans = INT_MAX;

        for (int i = 1; i < v.size(); i++) {
            ans = min(ans, abs(v[i] - v[i - 1]));
        }

        return ans;
    }
};