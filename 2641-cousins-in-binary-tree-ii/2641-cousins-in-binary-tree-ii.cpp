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
    int recursion(TreeNode* root, unordered_map<TreeNode*, int>&sib){
        if(!root) return 0;

        int left = recursion(root -> left, sib);
        int right = recursion(root -> right, sib);
        if(root -> left)
        sib[root -> left] = left + right;
        if(root -> right)
        sib[root -> right] = left + right;
        return root -> val;
    }
    void recursions(TreeNode* root, unordered_map<int, int>&level, int lev){
        if(!root) return ;
        
        level[lev] += root -> val;
        recursions(root -> left, level, lev + 1);
        recursions(root -> right, level, lev + 1);
    }
    void solve(TreeNode* root, int lev, unordered_map<TreeNode*, int>& sib, unordered_map<int, int>& level){
        if(!root) return;

        root -> val = level[lev] - sib[root];
        solve(root -> left, lev + 1, sib, level);
        solve(root -> right, lev + 1, sib, level);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int>sib;
        recursion(root, sib);
        unordered_map<int, int>level;
        recursions(root, level, 0);
        solve(root, 0, sib, level);
        root -> val = 0;
        return root;
    }
};