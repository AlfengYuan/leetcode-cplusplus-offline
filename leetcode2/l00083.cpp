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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> mymap;
        ListNode *p = head;
        while(p){
            if(mymap.count(p->val) == 0){
                mymap[p->val] = 1;
            }else{
                mymap[p->val]++;
            }
            p = p->next;
        }

        ListNode *q = new ListNode(-200, nullptr);
        ListNode *res = q;
        p = head;
        while(p){
            if(mymap[p->val] > 1){
                mymap[p->val]--;
            }else{
                q->next = p;
                q = p;
            }
            p = p->next;
        }
        q->next = nullptr;
        return res->next;
    }
};