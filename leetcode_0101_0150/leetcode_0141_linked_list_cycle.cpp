/**
 * Definition for singly-linked list. */

#include <cstdlib>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(1)
        {
            if(fast->next == NULL || fast->next->next == NULL) return false;
            if(fast->next->next == slow->next) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution solution = Solution();
    bool result = solution.hasCycle(head);
    if(result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}