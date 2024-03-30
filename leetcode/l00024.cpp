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
    ListNode* swapPairs(ListNode* head) {
        return reverseKGroup(head, 2);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        stack<int> mystack;
        vector<int> myvec;
        ListNode *p = head;
        ListNode *q = p;
        while(p){
            while(p && mystack.size() < k){
                mystack.push(p->val);
                p = p->next;
            }

            if(mystack.size() == k){
                while(!mystack.empty()){
                    myvec.push_back(mystack.top());
                    mystack.pop();
                }
                q = p;
            } else {
                while(q){
                    myvec.push_back(q->val);
                    q = q->next;
                }
            }
        }

        p = head;
        for(int i = 0; i<myvec.size(); i++){
            p->val = myvec[i];
            p = p->next;
        }

        return head;
    }
};