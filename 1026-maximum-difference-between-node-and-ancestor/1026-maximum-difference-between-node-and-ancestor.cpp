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
    void recursion(TreeNode* root, int maxi, int mini, int& diff){
        if(!root) return;

        maxi = max(maxi, root -> val);
        mini = min(mini, root -> val);

        diff = max(abs(maxi - mini), diff);

        recursion(root -> left, maxi, mini, diff);
        recursion(root -> right, maxi, mini, diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        recursion(root, INT_MIN, INT_MAX, diff);
        return diff;
    }
};