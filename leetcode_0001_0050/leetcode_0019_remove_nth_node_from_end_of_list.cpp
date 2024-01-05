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
        ListNode *p1 = head;
        ListNode *p2 = head;
        int sz = 0;
        while(p1){
            sz++;
            p1 = p1->next;
        }

        if(sz==n) return head->next;
        for(int i = 1; i<sz-n; i++)
        {
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        
        return head;

    }
};