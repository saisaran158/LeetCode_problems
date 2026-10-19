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
    map<pair<TreeNode* ,int>, int> dp;
    int rec(TreeNode* root, int flag){
        if(!root) return 0;
        if(dp.find({root, flag}) != dp.end())
        return dp[{root, flag}];
        int curr = 0;
        if(flag == -1){
            if(root -> left){
                curr = max(curr, 1 + rec(root -> left, 0));
            }
            if(root -> right){
                curr = max(curr, 1 + rec(root -> right, 1));
            }
        }
        if(flag == 1 && root -> left){
            curr = 1 + rec(root -> left, 0);
        }
        if(flag == 0 && root -> right){
            curr = 1 + rec(root -> right, 1);
        }
        return dp[{root, flag}] = curr;
    }
    void solve(TreeNode* root, int& ans){
        if(!root) return;
        ans = max(ans, rec(root, -1));
        solve(root -> left, ans);
        solve(root -> right, ans);
    }
    int longestZigZag(TreeNode* root) {
        // dp.clear();
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};