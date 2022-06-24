class LRUCache {
    unordered_map<int,list<pair<int, int>>::iterator> mp;
    int n;
    list<pair<int,int>> dll;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        auto iterr = mp.find(key);
        if(iterr==mp.end())
            return -1;
        dll.splice(dll.begin(),dll,mp[key]);
        return mp[key]->second;

    }
    
    void put(int key, int value) {
        auto iterr = mp.find(key);
        if(iterr!=mp.end())
        {
            dll.splice(dll.begin(),dll,mp[key]);
            mp[key]->second=value;
            return;
        }
        if(dll.size()==n)
        {
            int del = dll.back().first;
            dll.pop_back();
            mp.erase(del);
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */