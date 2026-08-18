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
    int recursion(TreeNode* root, int& ans) {
        if (!root)
            return 0;
        int a = recursion(root->left, ans);
        int b = recursion(root->right, ans);
        if (a == 0 && b == 0)
            return 2;
        if (a == 2 || b == 2) {
            ans++;
            return 1;
        }
        if (a == 1 || b == 1) {
            return 0;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        int x = recursion(root, ans);
        if(x == 2) return ans + 1;
        return ans;
    }
};