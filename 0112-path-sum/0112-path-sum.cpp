/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool recursion(TreeNode* root, int sum, int& targetSum){
        if(!root) return NULL;

        if(!root -> left && !root -> right){
            sum += root -> val;
            if(sum == targetSum) return true;
        }

        return recursion(root -> left, sum + root -> val, targetSum) || 
            recursion(root -> right, sum + root -> val, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return recursion(root, 0, targetSum);
    }
};