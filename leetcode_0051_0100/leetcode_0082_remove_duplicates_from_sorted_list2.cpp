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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        bool flag = true;

        while(head)
        {
            while(head->next && head->next->val == head->val)
            {
                head = head->next;
                flag = false;
            }

            if(flag == true)
            {
                p->next = head;
                p = p->next;
            }

            head = head->next;
            flag = true;
        }

        p->next = head;

        return result->next;
    }
};