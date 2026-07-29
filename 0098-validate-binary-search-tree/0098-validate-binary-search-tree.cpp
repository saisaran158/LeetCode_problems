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
    bool recursion(TreeNode* root, long long lb, long long ub){
        if(root == NULL) return true;

        if(root -> val <= lb || root -> val >= ub){
            return false;
        }

        return recursion(root -> left, lb, root -> val) && recursion(root -> right, root -> val, ub);
    }
    bool isValidBST(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL) return true;
        return recursion(root, LLONG_MIN, LLONG_MAX);
    }
};