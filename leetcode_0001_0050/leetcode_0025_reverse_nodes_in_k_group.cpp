#include <vector>
#include <iostream>
#include <cstdlib>
#include <stack>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode *> vec;
        stack<ListNode *> mystack;
        ListNode *res = new ListNode(0);
        ListNode *res_copy = res;
        int i;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }

        for(i = 0; i<(vec.size() / k * k); ++i)
        {
            mystack.push(vec[i]);
            if(mystack.size() == k)
            {
                while(!mystack.empty())
                {
                    res_copy->next = mystack.top();
                    res_copy = res_copy->next;
                    mystack.pop();
                }
            }
        }

        while(i < vec.size())
        {
            res_copy->next = vec[i];
            res_copy = res_copy->next;
            ++i;
        }

        res_copy->next = nullptr;

        return res->next;

    }
};

int main(int argc, char *argv[])
{
    ListNode *head               = new ListNode(1);
    head->next                   = new ListNode(2);
    head->next->next             = new ListNode(3);
    head->next->next->next       = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 3;
    Solution solution = Solution();
    ListNode *res = solution.reverseKGroup(head, k);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;
    return 0;
}