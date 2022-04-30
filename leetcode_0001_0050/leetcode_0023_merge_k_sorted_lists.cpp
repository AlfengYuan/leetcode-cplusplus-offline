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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> vec;
        ListNode *res = new ListNode(0);
        ListNode *res_copy = res;
        while(!this->isempty(lists))
        {
            ListNode *tmp = nullptr;
            int tmp_index = -1;
            for(int i = 0; i<lists.size(); ++i)
            {
                if(lists[i])
                {
                    if(tmp == nullptr) {tmp = lists[i]; tmp_index = i; }
                    else
                    {
                        if(lists[i]->val < tmp->val)
                        {
                            tmp = lists[i];
                            tmp_index = i;
                        }
                    }
                }
            }
            if(tmp_index >= 0) lists[tmp_index] = lists[tmp_index]->next; 
            vec.push_back(tmp);
        }

        for(int i = 0; i<vec.size(); ++i)
        {
            res_copy->next = vec[i];
            res_copy = res_copy->next;
        }
        
        return res->next;
    }

private:
    bool isempty(vector<ListNode *> &lists)
    {
        for(int i = 0; i<lists.size(); ++i)
        {
            if(lists[i]) return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    ListNode *head1    = new ListNode(1);
    head1->next        = new ListNode(4);
    head1->next->next  = new ListNode(5);

     ListNode *head2    = new ListNode(1);
    head2->next        = new ListNode(3);
    head2->next->next  = new ListNode(4);

    ListNode *head3    = new ListNode(2);
    head3->next        = new ListNode(6);

    vector<ListNode *> lists = {head1, head2, head3};
   
    Solution solution = Solution();
    ListNode *res = solution.mergeKLists(lists);
    cout << "[";
    while(res)
    {
        cout << res->val << ", ";
        res = res->next;
    }
    cout << "]" << endl;

    return 0;
}