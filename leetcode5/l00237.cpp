/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *before = node;
        while(node->next){
            node->val = node->next->val;
            before = node;
            node = node->next;
        }
        before->next = nullptr;
    }
};