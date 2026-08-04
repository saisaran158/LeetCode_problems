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
    void recursion(TreeNode* root, int sum, int& targetSum,
                   vector<vector<int>>& ans, vector<int>& ds) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            ds.push_back(root->val);
            sum += root->val;
            if (targetSum == sum) {
                ans.push_back(ds);
            }
            ds.pop_back();
            return;
        }

        ds.push_back(root->val);
        sum += root->val;
        recursion(root->left, sum, targetSum, ans, ds);
        recursion(root->right, sum, targetSum, ans, ds);
        ds.pop_back();
        sum -= root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursion(root, 0, targetSum, ans, ds);
        return ans;
    }
};