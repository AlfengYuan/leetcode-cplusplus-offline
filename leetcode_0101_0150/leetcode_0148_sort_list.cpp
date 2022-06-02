#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class comp {
public:
    bool operator() (ListNode *i, ListNode *j) {
        return (i->val < j->val);
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *result = new ListNode(0);
        vector<ListNode *> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        std::sort(vec.begin(), vec.end(), comp());
        head = result;
        for(auto &v: vec)
        {
            head->next = v;
            head = head->next;
        }

        head->next = nullptr;
        return result->next;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head         = new ListNode(4);
    head->next             = new ListNode(2);
    head->next->next       = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution = Solution();
    ListNode *result = solution.sortList(head);
    cout << "[";
    while(result)
    {
        cout << result->val << ", ";
        result = result->next;
    }
    cout << "]" << endl;

    return 0;
}