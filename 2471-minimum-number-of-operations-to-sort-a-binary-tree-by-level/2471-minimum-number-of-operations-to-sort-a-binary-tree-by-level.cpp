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
    int cycle(vector<int>& curr, vector<int>& sorted) {
        int n = curr.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[sorted[i]] = i;
        }
        vector<pair<int, int>> vp;
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int c = 0;
            int j = i;
            while(!vis[j]){
                vis[j] = 1;
                c++;
                j = mp[curr[j]];
            }
            ans += (c - 1);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> sorted;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                sorted.push_back(node->val);
            }
            vector<int> curr = sorted;
            sort(sorted.begin(), sorted.end());
            ans += cycle(curr, sorted);
        }
        return ans;
    }
};