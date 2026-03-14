/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        map<int, int> mp;  // hd -> node value
        queue<pair<Node*, int>> q;  // node, horizontal distance

        q.push({root, 0});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // store first node for this horizontal distance
            if(mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if(node->left) {
                q.push({node->left, hd - 1});
            }

            if(node->right) {
                q.push({node->right, hd + 1});
            }
        }

        for(auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};