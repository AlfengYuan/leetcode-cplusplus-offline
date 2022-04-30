#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode *head_copy = head;
        int listLen = 0;
        while(head_copy)
        {
            ++listLen;
            head_copy = head_copy->next;
        }

        ListNode *res = head;
        ListNode *afterK = res;
        k = k % listLen;
        while(k--)
        {
            afterK = afterK->next;
        }

        while(afterK->next)
        {
            res = res->next;
            afterK = afterK->next;
        }

        afterK->next = head;
        ListNode *resHead = res->next;
        res->next = nullptr;
        return resHead;

    }
};

int main(int argc, char *argv[])
{
    ListNode *head               = new ListNode(1);
    head->next                   = new ListNode(2);
    head->next->next             = new ListNode(3);
    head->next->next->next       = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution = Solution();
    int k = 2;
    ListNode *res = solution.rotateRight(head, k);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;
    return 0;
}