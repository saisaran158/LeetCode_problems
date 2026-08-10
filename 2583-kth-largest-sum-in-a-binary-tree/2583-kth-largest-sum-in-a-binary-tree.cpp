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
    void recursion(TreeNode* root, unordered_map<long long, long long>& level, int lev){
        if(!root) return;

        level[lev] += root -> val;
        recursion(root -> left, level, lev + 1);
        recursion(root -> right, level, lev + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<long long, long long>level;
        recursion(root, level, 0);
        vector<pair<long long, long long>>vp(level.begin(), level.end());
        sort(vp.begin(), vp.end(),[](auto a, auto b){
            return a.second > b.second;
        });
        long long x = 0;
        for(auto l : vp){
            x++;
            if(x == k)
            return l.second;
        }
        return -1;
    }
};