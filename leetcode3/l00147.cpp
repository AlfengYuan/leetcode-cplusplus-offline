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
    ListNode* insertionSortList(ListNode* head) {

        ListNode *output = new ListNode(-5005);
        while(head){
            ListNode *p = output;
            ListNode *q = p;
            while(p && head->val > p->val){
                q = p;
                p = p->next;
            }
            q->next = new ListNode(head->val);
            q = q->next;
            q->next = p;
            ListNode *input = head;
            head = head->next;
            input = nullptr;
            delete input;
        }

        return output->next;


    }
};