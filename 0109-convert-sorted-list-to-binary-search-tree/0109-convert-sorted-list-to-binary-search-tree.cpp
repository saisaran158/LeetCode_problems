/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* build(ListNode* start, ListNode* end){
        if(start == NULL || end == NULL) return NULL;
        if(start == end) return new TreeNode(start -> val);
        ListNode* slow = start;
        ListNode* fast = start;
        ListNode* prev = nullptr;
        while(fast != end && fast -> next != end){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        TreeNode* root = new TreeNode(slow -> val);

        root -> left = build(start, prev);
        root -> right = build( slow -> next, end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* start = head;
        ListNode* end = head;
        while(end -> next != NULL){
            end = end -> next;
        }
        TreeNode* root = build(start, end);
        return root;
    }
};