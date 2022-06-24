class LFUCache {
    int cap;
    int size;
    int minfreq;
    unordered_map<int,pair<int,int>> key_val;
    unordered_map<int,list<int>> freq_list;
    unordered_map<int,list<int>::iterator> key_iter;
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(key_val.count(key)==0)
            return -1;
        
        int to_return = key_val[key].first;
        
        freq_list[key_val[key].second].erase(key_iter[key]);
        key_val[key].second++;
        freq_list[key_val[key].second].push_back(key);
        key_iter[key] = --freq_list[key_val[key].second].end();
        
        if(freq_list[minfreq].size()==0 ) 
              minfreq++;
        
        return to_return;
    }
    
    void put(int key, int value) {
        if(cap<=0)
            return;
        
        if(get(key)!=-1)
        {
            key_val[key].first = value;
            return;
        }
        
        if(size>=cap)
        {
            key_val.erase(freq_list[minfreq].front());
            key_iter.erase(freq_list[minfreq].front());
            freq_list[minfreq].pop_front();
            size--;
        }
        
        key_val[key] = {value,1};
        freq_list[1].push_back(key);
        key_iter[key] = --freq_list[1].end();
        size++;
        minfreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */