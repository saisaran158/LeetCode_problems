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
    void recursion(TreeNode* root, int level, int& deep) {
        if (!root)
            return;
        deep = max(level, deep);
        recursion(root->left, level + 1, deep);
        recursion(root->right, level + 1, deep);
    }
    bool find(TreeNode* root, int level, int deep, TreeNode*& res) {
        if (!root)
            return false;
        if (root->left == NULL && root->right == NULL && level == deep) {
            res = root;
            return true;
        }
        bool a = find(root->left, level + 1, deep, res);
        bool b = find(root->right, level + 1, deep, res);
        if (a && b) {
            res = root;
            return true;
        }
        if(a || b){
            return true;
        }
        return false;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int deep = 0;
        recursion(root, 0, deep);
        TreeNode* res = NULL;
        find(root, 0, deep, res);
        return res;
    }
};