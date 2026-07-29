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
    int flag = 0;
    TreeNode* build(vector<vector<int>>& descriptions, int rooot,
                    map<int, int>& lchild, map<int, int>& rchild) {
        if (rooot == 0)
            return NULL;
        TreeNode* root = new TreeNode(rooot);

        root -> left = build(descriptions, lchild[rooot], lchild, rchild);
        root -> right = build(descriptions, rchild[rooot], lchild, rchild);
        
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, int> mp;
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
        map<int, int> lchild;
        map<int, int> rchild;
        for (int i = 0; i < descriptions.size(); i++) {
            if (descriptions[i][2] == 1) {
                lchild[descriptions[i][0]] = descriptions[i][1];
            } else {
                rchild[descriptions[i][0]] = descriptions[i][1];
            }
        }
        TreeNode* root = build(descriptions, rooot, lchild, rchild);
        return root;
    }
};