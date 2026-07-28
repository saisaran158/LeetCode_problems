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
    void recursion(TreeNode* a, TreeNode*b, int level){
        if(a==NULL || b==NULL){
            return;
        }
        if(level % 2 == 1)
        swap(a -> val, b -> val);
        recursion(a->right,b->left, level + 1);
        recursion(a->left,b->right, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return root;
        recursion(root -> left, root -> right, 1);
        return root;
    }
};