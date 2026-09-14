struct Node{
    Node* Links[26] = {NULL};
    bool flag = false;

    bool contains(char ch){
        return Links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node){
        Links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return Links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool getEnd(){
        return flag;
    }
};
class Trie {
Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr -> contains(word[i])){
                curr -> put(word[i], new Node());
            }
            curr = curr -> get(word[i]);
        }
        curr -> setEnd();
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(!curr -> contains(word[i])){
                return false;
            }
            curr = curr -> get(word[i]);
        }
        return curr -> getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!curr -> contains(prefix[i])){
                return false;
            }
            curr = curr -> get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */