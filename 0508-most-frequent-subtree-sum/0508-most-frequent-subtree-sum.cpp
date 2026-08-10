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
    int recursion(TreeNode* root, int& maxFreq, map<int, int>& mp){
        if(!root) return 0;
        int left = recursion(root -> left, maxFreq, mp);
        int right = recursion(root -> right, maxFreq, mp);
        int sum = left + right + root -> val;
        mp[sum]++;
        maxFreq = max(maxFreq, mp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxFreq = 0;
        map<int, int>mp;
        recursion(root, maxFreq, mp);
        vector<int>res;
        for(auto l : mp){
            if(l.second == maxFreq){
                res.push_back(l.first);
            }
        }
        return res;
    }
};