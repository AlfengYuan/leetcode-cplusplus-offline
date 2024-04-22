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
    void reorderList(ListNode* head) {
        deque<ListNode *> mydeque;
        ListNode *p = head->next;
        while(p){
            mydeque.push_back(p);
            p = p->next;
        }

        p = head;
        while(!mydeque.empty()){
            p->next = mydeque.back();
            mydeque.pop_back();
            p = p->next;
            if(!mydeque.empty()){
                p->next = mydeque.front();
                mydeque.pop_front();
                p = p->next;
            }
        }
        p->next = nullptr;
    }
};