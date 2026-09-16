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
    TreeNode* build(int preStart, int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder, unordered_map<int, int>& mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int index = mp[root -> val];
        int vals = index - inStart;

        root -> left = build(preStart + 1, preStart + vals, preorder, inStart, index - 1, inorder, mp);

        root -> right = build(preStart + vals + 1, preEnd, preorder, index + 1, inEnd, inorder, mp);        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int>mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = build(0, preorder.size() - 1, preorder, 0, inorder.size() -1, inorder, mp);

        return root;
    }
};