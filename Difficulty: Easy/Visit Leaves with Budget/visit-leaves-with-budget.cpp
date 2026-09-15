/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void findLeaves(Node* root, int level, vector<int>& cost) {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr) {
            cost.push_back(level);
            return;
        }

        findLeaves(root->left, level + 1, cost);
        findLeaves(root->right, level + 1, cost);
    }

    int getCount(Node *root, int k) {
        vector<int> cost;

        findLeaves(root, 1, cost);

        sort(cost.begin(), cost.end());

        int ans = 0;

        for(int x : cost) {
            if(k >= x) {
                k -= x;
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};