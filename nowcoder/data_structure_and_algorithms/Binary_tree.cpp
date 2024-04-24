#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int num) : val(num), left(nullptr), right(nullptr) {};
};

void inorderTree(Node *head){
    Node *curr = head;
    stack<Node *> mystk;
    while(curr || !mystk.empty()){
        while(curr){
            mystk.push(curr);
            curr = curr->left;

        }
        curr = mystk.top();
        mystk.pop();
        cout << curr->val << ",";
        curr = curr->right;
    }

}

void preorderTree(Node *head){
    Node *curr = head;
    stack<Node *> mystk;
    while(curr || !mystk.empty()){
        while(curr){
            mystk.push(curr);
            cout << curr->val << ",";
            curr = curr->left;
        }
        curr = mystk.top();
        mystk.pop();
        curr = curr->right;
    }

}

void postorderTree(Node *head){
    Node *curr = head;
    stack<Node *> mystk1;
    stack<Node *> mystk2;
    if(!head) return;
    mystk1.push(head);
    while(!mystk1.empty()){
        mystk2.push(mystk1.top());
        mystk1.pop();
        Node *curr = mystk2.top();
        if(curr && curr->left){
            mystk1.push(curr->left);
        }
        if(curr && curr->right){
            mystk1.push(curr->right);
        }

    }

    while(!mystk2.empty()){
        cout << mystk2.top()->val<< ",";
        mystk2.pop();
    }
}

void dfsInorder(Node *head){
    if(!head) return;
    
    dfsInorder(head->left);
    cout << head->val << " ";
    dfsInorder(head->right); 
}

void dfspreorder(Node *head){
    if(!head) return;
    cout << head->val << " ";
    dfspreorder(head->left);
    dfspreorder(head->right); 
}

void dfspostorder(Node *head){
    if(!head) return;
    
    dfspostorder(head->left);
    dfspostorder(head->right);
    cout << head->val << " "; 
}

int main(int argc, char *argv[]){
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    head->left->right->left = new Node(8);
    head->right->right->right = new Node(9);
    
    cout << "Inorder:" << endl;
    dfsInorder(head);
    cout << endl;
    inorderTree(head);
    cout << endl;
    cout << "Preorder:" << endl;
    dfspreorder(head);
    cout << endl;
    preorderTree(head);
    cout << endl;
    cout << "Postorder:" << endl;
    dfspostorder(head);
    cout << endl;
    postorderTree(head);
    cout << endl;

    return 0;

}