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
    vector<int>pre;
    void preordering(Node* root){
        if(root == NULL) return;
        pre.push_back(root -> val);
        for(auto &i : root -> children){
            preordering(i);
        }
    }
    vector<int> preorder(Node* root) {
        preordering(root);
        return pre;
    }
};