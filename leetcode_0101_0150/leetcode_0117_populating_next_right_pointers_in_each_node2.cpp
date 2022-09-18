/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        deque<Node *> mydeque;
        mydeque.push_back(root);
        while(!mydeque.empty())
        {
            vector<Node *> tmp;
            int currSize = mydeque.size();
            Node *before = mydeque.front();
            for(int i = 0; i<currSize; i++)
            {
                Node *curr = mydeque.front();
                if(curr->left) mydeque.push_back(curr->left);
                if(curr->right) mydeque.push_back(curr->right);
                mydeque.pop_front();
                tmp.push_back(curr);
                if(i > 0)
                {
                    before->next = curr;
                    before = curr;
                }
            }
            before->next = nullptr;
        }

        return root;
        
    }
};