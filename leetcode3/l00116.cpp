class Solution {
public:
    Node* connect(Node* root) {
        return levelOrder(root);
    }

    Node* levelOrder(Node* root) {
        queue<Node*> myq;
        //vector<vector<int>> res;
        if (!root) return root;
        myq.push(root);
        while (!myq.empty()) {
            int n = myq.size();
            //vector<int> tmp;
            Node* curr = myq.front(); myq.pop();
            if (curr->left) myq.push(curr->left);
            if (curr->right) myq.push(curr->right);

            for (int i = 0; i < n - 1; i++) {
                curr->next = myq.front(); myq.pop();
                curr = curr->next;
                if (curr->left) myq.push(curr->left);
                if (curr->right) myq.push(curr->right);
            }
           
            /*while (n--) {
                Node* curr = myq.front();
                tmp.push_back(curr->val);
                if (curr->left) myq.push(curr->left);
                if (curr->right) myq.push(curr->right);
                myq.pop();
            }*/
            //res.push_back(tmp);
        }

        return root;
    }
};