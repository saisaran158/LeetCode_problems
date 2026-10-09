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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        int k = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>now;
            int s = q.size();
            for(int i = 0; i < s; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left)
                q.push(node -> left);
                if(node -> right)
                q.push(node -> right);
                now.push_back(node -> val);
            }
            if(k % 2){
                reverse(now.begin(), now.end());
            }
            res.push_back(now);
            k++;
        }
        return res;
    }
};