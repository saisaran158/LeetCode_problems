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
    int level = 0;
    void recursion(TreeNode* root, int cur, int &res){
        if(root == NULL) return;
        if(cur > level){
            res = root -> val;
            level = cur;
        }
        recursion(root -> left, cur + 1, res);
        recursion(root -> right, cur + 1, res);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL)
        return root -> val;
        int res = 0;
        int cur = 0;
        recursion(root, cur, res);
        return res;
    }
};