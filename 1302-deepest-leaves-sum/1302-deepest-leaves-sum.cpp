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
    map<int, int> mp;
    int level = 0;
    void recursion(TreeNode* root, int curr, int& level) {
        if (root == NULL)
            return;
        if (curr > level) {
            level = curr;
            mp[curr] = root->val;
        } else {
            mp[curr] += root->val;
        }

        recursion(root->left, curr + 1, level);
        recursion(root->right, curr + 1, level);
    }
    int deepestLeavesSum(TreeNode* root) {
        int curr = 0;
        recursion(root, curr, level);
        return mp[mp.size() - 1];
    }
};