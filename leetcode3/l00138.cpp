/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        vector<Node *> myvec;
        unordered_map<Node*, int> mymap;
        Node* q = head;
        while (q) {
            mymap[q] = myvec.size();
            myvec.push_back(new Node(q->val));
            q = q->next;
        }

        for (int i = 0; i < myvec.size()-1; i++) {
            myvec[i]->next = myvec[i + 1];
        }

        Node* p = head;
        int index = 0;
        while (p)
        {
            if (p->random) {
                myvec[index]->random = myvec[mymap[p->random]];
            }
            index++;
            p = p->next;
        }

        return myvec[0];
    }
};