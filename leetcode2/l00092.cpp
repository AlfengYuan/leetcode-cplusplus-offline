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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ll = nullptr;
        ListNode *l = head;
        stack<ListNode *> mystack;
        for(int i = 1; i<left; i++){
            ll = l;
            l = l->next;
        }
        
        ListNode *lr = l->next;

        ListNode *rl = ll;
        ListNode *r = l;

        for(int i = left; i<right; i++){
            mystack.push(r);
            rl = r;
            r = r->next;
        }
        mystack.push(r);

        cout << mystack.size() << endl;

        ListNode *rr = r->next;

        ListNode *curr = mystack.top();
        if(ll) ll->next = curr;
        else head = curr;
        mystack.pop();
        while(!mystack.empty()){
            curr->next = mystack.top();
            mystack.pop();
            curr = curr->next;
        }
        curr->next = rr;
        // if(r && lr != r) r->next = lr;
        // if(rl && rl != l) rl->next = l;
        // if(l && r && lr && rl && lr==r && rl==l) r->next = l;
        // if(l) l->next = rr;

        return head;

    }
};