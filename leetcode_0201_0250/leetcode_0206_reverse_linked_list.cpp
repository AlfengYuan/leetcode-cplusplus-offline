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
    ListNode* reverseList(ListNode* head) {
        stack<int> mystack;
        ListNode *result = head;
        while(head)
        {
            mystack.push(head->val);
            head = head->next;
        }

        head = result;

        while(result)
        {
            result->val = mystack.top();
            mystack.pop();
            result = result->next;  
        }

        return head;
        
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(0);
    head->next                          = new ListNode(1);
    head->next->next                    = new ListNode(2);
    head->next->next->next              = new ListNode(3);
    head->next->next->next->next        = new ListNode(4);
    head->next->next->next->next->next  = new ListNode(5);

    Solution solution = Solution();
    ListNode *result = solution.reverseList(head);
    cout << "[";
    while(result)
    {
        cout << result->val << ", ";
        result = result->next;
    }
    cout << "]" << endl;

    return 0;
}