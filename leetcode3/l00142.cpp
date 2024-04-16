/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *low = head;
        ListNode *fast = hasCycle(head);
        if(!fast) return nullptr;
        while(low != fast){
            low = low->next;
            fast = fast->next;
        }
        
        return low;
    }

    ListNode *hasCycle(ListNode *head) {
        ListNode *low = head;
        ListNode *fast = head;
        while(low && fast){
           low = low->next;
           if(fast->next) fast = fast->next->next;
           else return nullptr;
           if(low && fast && low == fast) return fast;
        }

        return nullptr;
        
    }
};