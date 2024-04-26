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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *before = new ListNode(0, head);
        ListNode *res = before;
        ListNode *curr = head;
        while(curr){
            if(curr->val== val){
                before->next = curr->next;
            }else{
                before = curr;
            }
            curr = curr->next;
        }

        return res->next;
    }
};