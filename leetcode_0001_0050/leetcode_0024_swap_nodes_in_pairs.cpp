#include <vector>
#include <iostream>
#include <cstdlib>

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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode *> vec;
        ListNode *res = new ListNode(0);
        ListNode *res_copy = res;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }

        for(int i = 0; i<vec.size(); ++i)
        {
            if(i % 2 == 1)
            {
                ListNode *tmp = vec[i];
                vec[i] = vec[i-1];
                vec[i-1] = tmp;
            }
        }

        for(int i = 0; i<vec.size(); ++i)
        {
            res_copy->next = vec[i];
            res_copy = res_copy->next;
        }

        res_copy->next = nullptr;
        return res->next;

    }
};

int main(int argc, char *argv[])
{
    ListNode *head         = new ListNode(1);
    head->next             = new ListNode(2);
    head->next->next       = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution = Solution();
    ListNode *res = solution.swapPairs(head);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;
    return 0;
}