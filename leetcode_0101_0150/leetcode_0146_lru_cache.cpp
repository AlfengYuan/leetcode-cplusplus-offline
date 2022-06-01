/*solution from [https://blog.lichangao.com/daily_practice/leetcode/overview/question_summary.html]*/
#include <unordered_map>
#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node():key(0), val(0), prev(nullptr), next(nullptr) {}
    Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    Node *head, *tail;
    unordered_map<int, Node*> h;
    int capacity, size;

    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!h.count(key))
        {
            cout << "return -1 (not found)" << endl;
            return -1;
        }
        Node *node = h[key];
        removeNode(node);
        addNodeToHead(node);
        cout << "return " << node->val <<endl;
        return node->val;
    }
    
    void put(int key, int value) {
        if(h.count(key))
        {
            Node *node = h[key];
            node->val = value;
            removeNode(node);
            addNodeToHead(node);
        }
        else
        {
            if(size == capacity)
            {
                Node *removed = tail->prev;
                h.erase(removed->key);
                removeNode(removed);
                size--;
            }
            Node *node = new Node(key, value);
            addNodeToHead(node);
            h[key] = node;
            size++;
        }

        cout << "cache is {";
        for(auto &hv: h)
        {
            assert(hv.first == hv.second->key);
            cout << hv.second->key << "=" << hv.second->val << ", ";
        }
        cout << "}" << endl;

    }

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char *argv[])
{
    int capacity = 2;
    LRUCache *obj = new LRUCache(capacity);
    obj->put(1, 1);
    obj->put(2, 2);
    obj->get(1);
    obj->put(3, 3);
    obj->get(2);
    obj->put(4, 4);
    obj->get(1);
    obj->get(3);
    obj->get(4);

    return 0;
}