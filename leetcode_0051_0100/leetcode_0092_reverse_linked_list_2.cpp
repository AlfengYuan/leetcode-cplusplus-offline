#include <iostream>
#include <stack>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *head_copy = head;
        ListNode *leftBefore = head;
        ListNode *res = head;
        stack<ListNode *> mystack;
        int left_copy = left;
        while(--left_copy)
        {
            leftBefore = head_copy;
            head_copy = head_copy->next;
        }

        for(int i = 0; i<right-left+1;++i)
        {
            mystack.push(head_copy);
            head_copy = head_copy->next;
        }

        if(left == 1) res = mystack.top();
        while(!mystack.empty())
        {
            leftBefore->next = mystack.top();
            mystack.pop();
            leftBefore = leftBefore->next;
        }

        leftBefore->next = head_copy;

        return res;
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
    int left = 2, right = 4;
    ListNode *res = solution.reverseBetween(head, left, right);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;
    return 0;
}