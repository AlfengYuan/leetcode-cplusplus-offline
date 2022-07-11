#include <map>
#include <vector>
#include <stack>
#include <iostream>
#include <set>
using namespace std;
class Trie {
    map<string, int> root;
    map<string, int> sub;
public:
    Trie() {
        this->root.clear();
        this->sub.clear();
    }

    void insert(string word) {
        root[word] += 1;
        string tmp = "";
        for (int i = 0; i < word.size() - 1; i++)
        {
            tmp += word[i];
            sub[tmp] += 1;
        }
    }

    bool search(string word) {
        if (root.find(word) != root.end()) return true;
        return false;
    }

    bool startsWith(string prefix) {
        if (this->search(prefix)) return true;
        else
        {
            if (this->sub.find(prefix) != this->sub.end()) return true;
            else return false;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    Trie tree = Trie();
    tree.insert("apple");
    tree.search("apple");
    tree.search("app");
    tree.startsWith("app");
    tree.insert("app");
    tree.search("app");

    return 0;
}