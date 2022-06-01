#include <iostream>
#include <vector>

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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *result = new ListNode(0);
        vector<ListNode *> vec;
        while(head)
        {
            vec.push_back(head);
            head = head->next;
        }
        insertSort(vec);

        head = result;
        for(auto &v: vec)
        {
            head->next = v;
            head = head->next;
        }

        head->next = nullptr;
        return result->next;
    }

private:

    void insertSort(vector<ListNode *> &vec) {
    // 从第二个数开始，往前插入数字
    for (size_t i = 1; i < vec.size(); i++) {
        int currentNumber = vec[i]->val;
        int j = i - 1;
        // 寻找插入位置的过程中，不断地将比 currentNumber 大的数字向后挪
        while (j >= 0 && currentNumber < vec[j]->val) {
            vec[j + 1]->val = vec[j]->val;
            j--;
        }
        // 两种情况会跳出循环：1. 遇到一个小于或等于 currentNumber 的数字，跳出循环，currentNumber 就坐到它后面。
        // 2. 已经走到数列头部，仍然没有遇到小于或等于 currentNumber 的数字，也会跳出循环，此时 j 等于 -1，currentNumber 就坐到数列头部。
        vec[j + 1]->val = currentNumber;
    }
}
};

int main(int argc, char *argv[])
{
    ListNode *head         = new ListNode(4);
    head->next             = new ListNode(2);
    head->next->next       = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution = Solution();
    ListNode *result = solution.insertionSortList(head);
    cout << "[";
    while(result)
    {
        cout << result->val << ", ";
        result = result->next;
    }
    cout << "]" << endl;

    return 0;
}


