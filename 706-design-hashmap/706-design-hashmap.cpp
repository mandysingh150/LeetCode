class MyHashMap {
public:
    // {key, value}
    vector<vector<pair<int,int>>> v;
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i=0 ; i<1e4+7 ; ++i)
            v.push_back({});
    }
    
    int hashFunction(int key) {
        return key%(int(1e4+7));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hashFunction(key);
        for(int i=0 ; i<v[index].size() ; ++i)
            if(v[index][i].first == key) {
                v[index][i].second = value;
                return;
            }
        v[index].push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hashFunction(key);
        for(int i=0 ; i<v[index].size() ; ++i)
            if(v[index][i].first == key)
                return v[index][i].second;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hashFunction(key);
        for(int i=0 ; i<v[index].size() ; ++i)
            if(v[index][i].first == key) {
                v[index].erase(v[index].begin()+i);
                return;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */