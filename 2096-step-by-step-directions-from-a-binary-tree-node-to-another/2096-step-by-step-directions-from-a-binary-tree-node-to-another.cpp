/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool recursion(TreeNode* root, int startValue, string& path) {
        if (!root)
            return false;
        if (root->val == startValue) {
            return true;
        }
        path.push_back('L');
        if (recursion(root->left, startValue, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if (recursion(root->right, startValue, path))
            return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";
        recursion(root, startValue, startPath);
        recursion(root, destValue, destPath);
        int i = 0;
        while (startPath[i] == destPath[i] && startPath.size() &&
               i < destPath.size()) {
            i++;
        }
        string res = "";
        for (int j = i; j < startPath.size(); j++) {
            res += 'U';
        }
        for (int j = i; j < destPath.size(); j++) {
            res += destPath[j];
        }
        return res;
    }
};