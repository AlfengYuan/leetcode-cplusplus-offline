/**
 * Definition for singly-linked list.*/
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *headA_copy = headA;
        ListNode *headB_copy = headB;
        while(headA_copy)
        {
            while(headB_copy)
            {
                if(headB_copy == headA_copy) return headA_copy;
                else headB_copy = headB_copy->next;
            }
            headA_copy = headA_copy->next;
            headB_copy = headB;
        }

        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    ListNode *commhead          = new ListNode(8);
    commhead->next              = new ListNode(4);
    commhead->next->next        = new ListNode(5);

    ListNode *headA   = new ListNode(4);
    headA->next       = new ListNode(1);
    headA->next->next = commhead;

    ListNode *headB           = new ListNode(5);
    headB->next               = new ListNode(6);
    headB->next->next         = new ListNode(1);
    headB->next->next->next   = commhead;
    
    Solution solution = Solution();
    ListNode *result = solution.getIntersectionNode(headA, headB);
    cout << "Intersected at " << "\'" << result->val << "\'" << endl;
    return 0;
}