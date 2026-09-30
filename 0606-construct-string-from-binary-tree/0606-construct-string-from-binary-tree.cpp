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
    string rec(TreeNode* root){
        if(!root) return "";
        if(root -> left == NULL && root -> right == NULL){
            return to_string(root -> val);
        }
        string res = to_string(root -> val);

        if(root -> left == NULL && root -> right != NULL){
            res += "()";
        }
        else{
            res += "(" + rec(root -> left) + ")";
        }
        if(root -> right != NULL)
        res += "(" + rec(root -> right) + ")";

        return res;
    }
    string tree2str(TreeNode* root) {
        return rec(root);
    }
};