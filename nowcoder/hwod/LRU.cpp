#include <list>
#include <iterator>
#include <unordered_map>
#include <map>
using namespace std;

class LRUCache {
public:
    int cap = 0;

    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        auto iter = map.find(key);
        //没有在map中找到
        if (iter == map.end())
            return -1;

        else
        {
            int value = iter->second->second;
            cache.push_front(*(iter->second));
            cache.erase(iter->second);
            map[key] = cache.begin();
            return value;
        } 
    }

    void put(int key, int value)
    {
        //先判断key是否存在
        auto iter = map.find(key);
        //key不存在
        if (iter == map.end())
        {
            //判断缓存容量是否已满
            if (cache.size() == cap)
            {
                //容量满需要释放cache 和map
                auto lst = cache.back();
                map.erase(lst.first);
                cache.pop_back();
            }
            //再插入
            cache.push_front({ key,value });
            map[key] = cache.begin();
        }

        //key已经存在
        else
        {
            //先将缓存中原数据删除
            cache.erase(iter->second);
            //再加入
            cache.push_front({ key,value });
            map[key] = cache.begin();   
        }
    }

protected:
    list<pair<int, int>> cache;
    unordered_map <int, list<pair<int, int>>::iterator> map;
};

int main(int argc, char *argv[])
{
    LRUCache cache (2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4

    return 0;
}

