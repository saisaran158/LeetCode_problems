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
    int ind = 0;
    void recursion(TreeNode* root, int &ans, int k){
        if(root == NULL) return;

        recursion(root -> left, ans, k);
        ind++;

        if(k == ind){
            ans = root -> val;
        }

        recursion(root -> right, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        recursion(root, ans, k);
        return ans;
    }
};