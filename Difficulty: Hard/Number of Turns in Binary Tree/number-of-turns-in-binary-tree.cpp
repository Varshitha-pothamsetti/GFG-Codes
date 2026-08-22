class Solution {
public:
    bool findPath(Node* root, int target, vector<char>& path) {
        if (root == NULL)
            return false;

        if (root->data == target)
            return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path))
            return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int first, int second) {
        if (first == second)
            return -1;

        vector<char> p1, p2;

        if (!findPath(root, first, p1) || !findPath(root, second, p2))
            return -1;

        int i = 0;

        while (i < p1.size() && i < p2.size() &&
               p1[i] == p2[i]) {
            i++;
        }

        vector<char> path;

        for (int j = p1.size() - 1; j >= i; j--)
            path.push_back(p1[j]);

        for (int j = i; j < p2.size(); j++)
            path.push_back(p2[j]);

        if (path.size() < 2)
            return -1;

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};