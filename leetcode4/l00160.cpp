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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, int> mymapA;
        while(headA){
            mymapA[headA] = 1;
            headA = headA->next;
        }

        while(headB){
            if(mymapA.count(headB) > 0){
                return headB;
            }
            headB = headB->next;
        }
        
        return nullptr;
    }
};