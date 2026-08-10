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
    void recursion(TreeNode* root, int target, int lev, vector<int>& level) {
        if (!root)
            return;
        if (root->val == target) {
            level[target] = lev;
        }
        recursion(root->left, target, lev + 1, level);
        recursion(root->right, target, lev + 1, level);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> level(101, 0);
        recursion(root, x, 0, level);
        recursion(root, y, 0, level);
        if (level[x] != level[y])
            return false;
        map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    mp[node->left->val] = node->val;
                    q.push(node->left);
                }
                if (node->right) {
                    mp[node->right->val] = node->val;
                    q.push(node->right);
                }
            }
        }
        if (mp[x] == mp[y])
            return false;
        return true;
    }
};