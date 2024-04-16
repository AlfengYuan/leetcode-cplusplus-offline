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
    bool hasCycle(ListNode *head) {
        ListNode *low = head;
        ListNode *fast = head;
        while(low && fast){
           low = low->next;
           if(fast->next) fast = fast->next->next;
           else return false;
           if(low && fast && low == fast) return true;
        }

        return false;
        
    }
};