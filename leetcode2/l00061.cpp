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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *fast = head;
        int n = 0;
        while(fast){
            fast = fast->next;
            n++;
        }
        fast = head;
        for(int i = 0; i<k % n; i++){
            fast = fast->next;
        }
        ListNode *low = head;
        while(fast->next){
            low = low->next;
            fast = fast->next;
        }

        fast->next = head;
        head = low->next;
        low->next = nullptr;

        return head;
    }
};