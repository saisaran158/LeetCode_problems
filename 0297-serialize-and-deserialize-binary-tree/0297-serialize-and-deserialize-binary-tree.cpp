/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string res="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                res.append("#,");
            }
            else{
                res.append(to_string(node->val)+",");
            }
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                cur->left=NULL;
            }
            else{
                TreeNode* node=new TreeNode(stoi(str));
                q.push(node);
                cur->left=node;
            }
            getline(s,str,',');
            if(str=="#"){
                cur->right=NULL;
            }
            else{
                TreeNode* node=new TreeNode(stoi(str));
                q.push(node);
                cur->right=node;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));