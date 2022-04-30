#include <iostream>
#include <cstdlib>

using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = p;
        for(int i = 0; i<n-1; ++i)
        {
            p = p->next;
        }

        if(!p->next) return head->next;
        ListNode *m = q;
        while(p->next)
        {
            m = q;
            q = q->next;
            p = p->next;
        }

        m->next = q->next;
        q = nullptr;

        return head;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    head->next                   = new ListNode(2);
    head->next->next             = new ListNode(3);
    head->next->next->next       = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    Solution solution = Solution();
    ListNode *res = solution.removeNthFromEnd(head, n);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]";

    return 0;
}

