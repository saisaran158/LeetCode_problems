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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int d = 1;
        int s = 0;
        if(depth == 1){
            TreeNode* nroot = new TreeNode(val);
            nroot -> left = root;
            return nroot;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            d++;
            s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(d == depth){
                    TreeNode* curL = curr -> left;
                    TreeNode* curR = curr -> right;
                    TreeNode* extra1 = new TreeNode(val);
                    TreeNode* extra2 = new TreeNode(val);
                    curr -> left = extra1;
                    curr -> right = extra2;
                    extra1 -> left = curL;
                    extra2 -> right = curR;
                }
                if(curr -> left){
                    q.push(curr -> left);
                }
                if(curr -> right){
                    q.push(curr -> right);
                }
            }
        }
        return root;
    }
};