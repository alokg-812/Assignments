#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache; // key -> (value, list iterator)
    list<int> order;
    void touch(int key) {
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = prev(order.end());
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; 
        }
        touch(key);
        return cache[key].first; 
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            touch(key);
        } else {
            if (cache.size() == capacity) {
                int lru = order.front();
                order.pop_front();
                cache.erase(lru);
            }
            order.push_back(key);
            cache[key] = {value, prev(order.end())};
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; 
    cache.put(3, 3);               
    cout << cache.get(2) << endl; 
    cache.put(4, 4);              
    cout << cache.get(1) << endl; 
    cout << cache.get(3) << endl; 
    cout << cache.get(4) << endl; 
}
