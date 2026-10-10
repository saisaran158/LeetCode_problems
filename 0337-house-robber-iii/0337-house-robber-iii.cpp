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
    int rec(TreeNode* root, unordered_map<TreeNode*, int>& mp){
        if(!root) return 0;
        if(mp.find(root) != mp.end())
        return mp[root];
        int take = root -> val;
        if(root -> left)
        take += rec(root -> left -> left, mp) + rec(root -> left -> right, mp);
        if(root -> right)
        take += rec(root -> right -> left, mp) + rec(root -> right -> right, mp);

        int dtake = rec(root -> left, mp) + rec(root -> right, mp);

        return mp[root] = max(take, dtake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>mp;
        return rec(root, mp);
    }
};