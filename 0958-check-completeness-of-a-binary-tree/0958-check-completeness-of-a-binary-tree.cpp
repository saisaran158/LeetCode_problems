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
    int count(TreeNode* root){
        if(root == NULL) return 0;

        return 1 + count(root -> left) + count(root -> right);
    }
    bool recursion(TreeNode* root, int index, int totalNodes){
        if(root == NULL) return true;
        if(index >= totalNodes) return false;
        return recursion(root -> left, 2*index + 1, totalNodes) && recursion(root -> right, 2*index + 2, totalNodes);
        
    }
    bool isCompleteTree(TreeNode* root) {
        int h = count(root);
        return recursion(root, 0, h);
    }
};