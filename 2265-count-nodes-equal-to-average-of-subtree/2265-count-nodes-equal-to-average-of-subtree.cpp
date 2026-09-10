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
    pair<int, int> recursion(TreeNode* root, int& ans){
        if(!root) return {0, 0};

        pair<int, int>left = recursion(root -> left, ans);
        pair<int, int>right = recursion(root -> right, ans);

        if((left.first + right.first + root -> val) / (left.second + right.second + 1) == root -> val){
            ans++;
        }
        
        return {left.first + right.first + root -> val, left.second + right.second + 1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        recursion(root, ans);
        return ans;
    }
};