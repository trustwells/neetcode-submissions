#include <cstring>
class MyHashSet {
private:
    int set[31251];

    int getMask(int key) {
        return 1 << (key % 32);
    }

public:
    MyHashSet() {
        std::memset(set, 0, sizeof(set));
    }
    
    void add(int key) {
        set[key / 32] |= getMask(key);
    }
    
    void remove(int key) {
        if (contains(key)) {
            set[key / 32] ^= getMask(key);
        }
    }
    
    bool contains(int key) {
        return (set[key / 32] & getMask(key)) != 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */