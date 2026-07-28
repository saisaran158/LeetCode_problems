/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> level;
        if(root == NULL) return level;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            vector<int>ans;
            int s = q.size();

            for(int i = 0; i < s; i++){
                Node* node = q.front();
                q.pop();
                for(auto i : node -> children){
                    q.push(i);
                }
                ans.push_back(node -> val);
            }
            level.push_back(ans);
        }
        return level;
    }
};