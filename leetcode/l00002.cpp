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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *result, *head;

      result = new ListNode(-1, nullptr);
      head = result;
      int sum = 0, add = 0;
      while(l1 && l2)
      {
        sum = l1->val + l2->val + add;
        add = sum / 10;
        ListNode *curr = new ListNode(sum % 10, nullptr);

        head->next = curr;
        head = head->next;

        l1 = l1->next;
        l2 = l2->next;
      }

      while(l1)
      {
        sum = l1->val + add;
        add = sum / 10;
        ListNode *curr = new ListNode(sum % 10, nullptr);

        head->next = curr;
        head = head->next;
        l1 = l1->next;
      }

      while(l2)
      {
        sum = l2->val + add;
        add = sum / 10;
        ListNode *curr = new ListNode(sum % 10, nullptr);

        head->next = curr;
        head = head->next;
        l2 = l2->next;
      }

      if(add > 0)
      {
        ListNode *curr = new ListNode(add % 10, nullptr);
        head->next = curr;
        head = head->next;
      }

      return result->next;

    }
};