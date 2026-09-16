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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = new ListNode(1);
        ListNode* res = head;
        while(temp1 && temp2){
            if(temp1 -> val < temp2 -> val){
                res -> next = new ListNode(temp1 -> val);
                temp1 = temp1 -> next;
                res = res -> next;
            }
            else if(temp1 -> val > temp2 -> val){
                res -> next = new ListNode(temp2 -> val);
                temp2 = temp2 -> next;
                res = res -> next;
            }
            else if(temp1 -> val == temp2 -> val){
                res -> next = new ListNode(temp1 -> val);
                temp1 = temp1 -> next;
                res = res -> next;
                res -> next = new ListNode(temp2 -> val);
                res = res -> next;
                temp2 = temp2 -> next;
            }
        }

        while(temp1){
            res -> next = new ListNode(temp1 -> val);
            res = res -> next;
            temp1 = temp1 -> next;
        }
        while(temp2){
            res -> next = new ListNode(temp2 -> val);
            res = res -> next;
            temp2 = temp2 -> next;
        }
        return head -> next;
    }
};