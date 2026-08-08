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
    void recursion(TreeNode* root, int& sum){
        if(!root) return;

        if(root -> left && root -> left -> left == NULL && root -> left -> right == NULL){
            sum += root -> left-> val;
        }
        recursion(root -> left, sum);
        recursion(root -> right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        recursion(root, sum);
        return sum;
    }
};