/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* prev = NULL;
    Node* flatten(Node* head) {
        if(head == NULL) return NULL;
        flatten(head -> next);
        flatten(head -> child);
        head -> next = prev;
        if(prev != NULL){
            prev -> prev = head;
        }
        head -> child = NULL;
        prev = head;
        return head;
    }
};