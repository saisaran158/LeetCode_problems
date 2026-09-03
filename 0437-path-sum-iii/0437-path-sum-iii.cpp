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
    int count = 0;
    void recursion(TreeNode* root, long long targetSum) {
        if (!root)
            return;
        if (targetSum == root->val) {
            count = count + 1;
        }
        recursion(root->left, targetSum - root->val);
        recursion(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        recursion(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};