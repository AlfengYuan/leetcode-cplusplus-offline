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
    int idx = 0;
public:
    int getIdx()
    {
        return this->idx;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *start = head;
        while(1)
        {
            if(fast->next == NULL || fast->next->next == NULL) return NULL;
            if(fast->next->next == slow->next)
            {
                fast = fast->next->next;
                while(fast != start)
                {
                    fast = fast->next;
                    start = start->next;
                    idx++;
                }
                return start;
            }
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
    ListNode *result = solution.detectCycle(head);
    if(result)
    {
        cout << "tail connects to node index "<< solution.getIdx() <<  endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    return 0;
}