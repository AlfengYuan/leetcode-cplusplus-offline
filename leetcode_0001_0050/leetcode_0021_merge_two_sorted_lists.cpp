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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *resHead = new ListNode(0);
        ListNode *res = resHead;
        while(list1 || list2)
        {
            while(list1 && list2)
            {
                if(list1->val <= list2->val)
                {
                    res->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else
                {
                    res->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
                res = res->next;
            }

            while(list1)
            {
                res->next = new ListNode(list1->val);
                list1 = list1->next;
                res = res->next;

            }

            while(list2)
            {
                res->next = new ListNode(list2->val);
                list2 = list2->next;
                res = res->next;
            }
        }

        return resHead->next;
    }
};

int main(int argc, char *argv[])
{
    ListNode *lists1 = new ListNode(1);
    lists1->next = new ListNode(2);
    lists1->next->next = new ListNode(4);

    ListNode *lists2 = new ListNode(1);
    lists2->next = new ListNode(3);
    lists2->next->next = new ListNode(4);

    Solution solution = Solution();
    ListNode *res = solution.mergeTwoLists(lists1, lists2);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;
    
    return 0;
}