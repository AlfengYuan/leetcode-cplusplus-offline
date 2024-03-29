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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = new ListNode(0);
        ListNode *r = p;
        p->next = head;
        ListNode *q = p;
        while(n--){
            q = q->next;
        }

        while(q->next){
            p = p->next;
            q = q->next;
        }

        p->next = p->next->next;

        return r->next;
    }
};