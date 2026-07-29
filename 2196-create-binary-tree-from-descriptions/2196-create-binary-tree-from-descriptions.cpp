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
    TreeNode* build(int rooot, unordered_map<int, int>& lchild,
                    unordered_map<int, int>& rchild) {
        if (rooot == 0)
            return NULL;
        TreeNode* root = new TreeNode(rooot);

        root->left = build(lchild[rooot], lchild, rchild);
        root->right = build(rchild[rooot], lchild, rchild);

        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> mp;
        for (int i = 0; i < descriptions.size(); i++) {
            mp[descriptions[i][1]]++;
        }
        int rooot = -1;
        for (int i = 0; i < descriptions.size(); i++) {
            if (mp[descriptions[i][0]] == 0) {
                rooot = descriptions[i][0];
                break;
            }
        }
        unordered_map<int, int> lchild;
        unordered_map<int, int> rchild;
        for (int i = 0; i < descriptions.size(); i++) {
            if (descriptions[i][2] == 1) {
                lchild[descriptions[i][0]] = descriptions[i][1];
            } else {
                rchild[descriptions[i][0]] = descriptions[i][1];
            }
        }
        TreeNode* root = build(rooot, lchild, rchild);
        return root;
    }
};