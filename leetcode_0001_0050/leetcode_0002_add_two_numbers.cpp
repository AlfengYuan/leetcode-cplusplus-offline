#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *result = res;
        int sum = 0, add = 0;
        while(l1 || l2)
        {
            while(l1 && l2)
            {
                sum = l1->val + l2->val + add;
                res->next = new ListNode(sum % 10);
                add = sum / 10;
                res = res->next;
                l1 = l1->next;
                l2 = l2->next;
            }

            while(l1)
            {
                sum = l1->val + add;
                res->next = new ListNode(sum % 10);
                add = sum / 10;
                res = res->next;
                l1 = l1->next;
            }

            while(l2)
            {
                sum = l2->val + add;
                res->next = new ListNode(sum % 10);
                add = sum / 10;
                res = res->next;
                l2 = l2->next;
            }

        }
        if(add > 0)
        {
            res->next = new ListNode(add);
            res = res->next;
        }
        return result->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution = Solution();
    ListNode *res = solution.addTwoNumbers(l1, l2);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next; 
    }
    cout << "]" << endl;
    return 0;
}