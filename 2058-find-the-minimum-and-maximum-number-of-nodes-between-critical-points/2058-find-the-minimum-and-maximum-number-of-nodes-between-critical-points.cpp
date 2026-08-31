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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;
        vector<int> vp;
        ListNode* prev = head;
        if (prev->next->next == NULL)
            return res;
        ListNode* temp = head->next;
        int c = 2;
        while (temp->next != NULL) {
            if (temp->val > prev->val && temp->val > temp->next->val) {
                vp.push_back(c);
            } else if (temp->val < prev->val && temp->val < temp->next->val) {
                vp.push_back(c);
            }
            c++;
            prev = temp;
            temp = temp->next;
        }
        if (vp.size() == 0 || vp.size() == 1)
            return res;
        sort(vp.begin(), vp.end());
        res[1] = vp[vp.size() - 1] - vp[0];
        int d = 1e9;
        for (int i = 0; i < vp.size() - 1; i++) {
            d = min(d, vp[i + 1] - vp[i]);
        }
        res[0] = d;
        return res;
    }
};