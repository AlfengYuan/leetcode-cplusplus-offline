/**
 * Definition for singly-linked list. */

#include <stack>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *before = result;
        while(head)
        {
            while(head && head->val == val) head = head->next;
            before->next = head;
            if(head)
            {
                head = head->next;
                before = before->next;
            }
        }

        return result->next;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    head->next                          = new ListNode(2);
    head->next->next                    = new ListNode(6);
    head->next->next->next              = new ListNode(3);
    head->next->next->next->next        = new ListNode(4);
    head->next->next->next->next->next  = new ListNode(5);
    head->next->next->next->next->next->next  = new ListNode(6);

    int val = 6;

    Solution solution = Solution();
    ListNode *result = solution.removeElements(head, val);
    cout << "[";
    while(result)
    {
        cout << result->val << ", ";
        result = result->next;
    }
    cout << "]" << endl;

    return 0;
}