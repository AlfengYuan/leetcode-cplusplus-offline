/**
 * Definition for singly-linked list. */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> vec;
        ListNode *head_copy;
        head_copy = head;
        while(head_copy)
        {
            vec.push_back(head_copy);
            head_copy = head_copy->next;
        }

        head_copy = head;
        for(int i = 1, j = vec.size()-1; i < j; i++, j--)
        {
            head_copy->next = vec[j];
            head_copy->next->next = vec[i];
            head_copy = head_copy->next->next; 
        }

        if(vec.size() % 2 == 0) 
        {
            head_copy->next  = vec[vec.size() / 2];
            head_copy = head_copy->next;
        }
        head_copy->next = nullptr;

    }
};

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution solution = Solution();
    solution.reorderList(head);
    
    cout << "[";
    while(head)
    {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << "]" << endl;;
    return 0;
}