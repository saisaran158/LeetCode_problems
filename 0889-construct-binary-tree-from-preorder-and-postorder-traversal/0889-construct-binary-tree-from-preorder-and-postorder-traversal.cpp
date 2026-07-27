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
    TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int>
    &postorder, int postStart, int postEnd, map<int, int> &postMap){
        if(preStart > preEnd || postStart > postEnd) return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;

        int inVal = postMap[preorder[preStart + 1]];
        int numsLeft = inVal - postStart;

        root -> left = build(preorder, preStart + 1, preStart + numsLeft + 1, postorder, postStart, postStart + numsLeft, postMap);

        root -> right = build(preorder, preStart + numsLeft + 2, preEnd, postorder, inVal + 1, postEnd - 1, postMap);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int, int>postMap;
        for(int i = 0; i < postorder.size(); i++) postMap[postorder[i]] = i;

        TreeNode* root = build(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1, postMap);
        return root;
    }
};