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
    ListNode* partition(ListNode* head, int x) {
        vector<int> left;
        vector<int> right;
        ListNode *p = head;
        while(p){
            if(p->val < x) left.push_back(p->val);
            else right.push_back(p->val);

            p = p->next;
        }
        p = head;
        int li = 0, ri=0;
        while(p){
            if(li < left.size()) p->val = left[li++];
            else p->val = right[ri++];
            p = p->next;
        }

        return head;
    }
};