class LRUCache {
public:
    int cap;
    LRUCache(int capacity) : cap(capacity){

    }
    
    int get(int key) {
        auto iter = map.find(key);
        if(iter == map.end()) return -1;
        int value = iter->second->second;
        cache.push_front(*(iter->second));
        cache.erase(iter->second);
        map[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto iter = map.find(key);
        if(iter == map.end()){
            if(cache.size() == cap){
                auto lst = cache.back();
                map.erase(lst.first);
                cache.pop_back();
            }
            cache.push_front({key, value});
            map[key] = cache.begin();
        }else{
            cache.erase(iter->second);
            cache.push_front({key, value});
            map[key] = cache.begin();
        }
    }
protected:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */