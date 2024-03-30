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
        vector<int> myvec;
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        for(ListNode *list : lists){
            p->next = list;
            while(list){
                myvec.push_back(list->val);
                if(!list->next) p = list;
                list = list->next;
            }
        }

        sort(myvec.begin(), myvec.end(), std::less<int>());

        p = result->next;
        for(int i = 0; i<myvec.size(); i++){
            p->val = myvec[i];
            p = p->next;
        }
        return result->next;
    }
};