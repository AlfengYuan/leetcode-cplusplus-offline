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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lh = new ListNode(0), *l = lh;
        ListNode *rh = new ListNode(0), *r = rh;
        for(ListNode *cur = head; cur; cur = cur->next)
        {
            if(cur->val < x) l = l->next = cur;
            else r = r->next = cur;
        }
        l->next = rh->next;
        r->next = nullptr;
        return lh->next;
    }
};