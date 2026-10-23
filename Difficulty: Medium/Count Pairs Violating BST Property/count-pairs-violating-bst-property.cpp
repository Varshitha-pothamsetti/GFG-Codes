/* BST Node Structure
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
    long long merge(vector<int>& a, vector<int>& temp, int l, int m, int r) {
        int i = l, j = m + 1, k = l;
        long long count = 0;

        while (i <= m && j <= r) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
                count += m - i + 1;
            }
        }

        while (i <= m)
            temp[k++] = a[i++];

        while (j <= r)
            temp[k++] = a[j++];

        for (int i = l; i <= r; i++)
            a[i] = temp[i];

        return count;
    }

    long long sortCount(vector<int>& a, vector<int>& temp, int l, int r) {
        if (l >= r) return 0;

        int m = l + (r - l) / 2;

        long long count = 0;
        count += sortCount(a, temp, l, m);
        count += sortCount(a, temp, m + 1, r);
        count += merge(a, temp, l, m, r);

        return count;
    }

    void inorder(Node* root, vector<int>& a) {
        if (root == NULL) return;

        inorder(root->left, a);
        a.push_back(root->data);
        inorder(root->right, a);
    }

    int pairsViolatingBST(Node* root) {
        vector<int> a;
        inorder(root, a);

        vector<int> temp(a.size());

        return (int)sortCount(a, temp, 0, a.size() - 1);
    }
};