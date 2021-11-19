#include "usual.h"

class List_Node {
public:
    int key;
    List_Node* succ;
    List_Node* prev;
    
    List_Node(): key(0), succ(nullptr), prev(nullptr) {}
    List_Node(int _key, List_Node* _succ, List_Node* _prev): key(_key), succ(_succ), prev(_prev) {}
    
    void insertAfter(List_Node* ln) {
        if (!ln)
            return;
        ln->succ = succ;
        ln->prev = this;
        if (succ) {
            succ->prev = ln;
        }
        succ = ln;
    }

    void removeAfter() {
        if (!succ)
            return;
        List_Node* tmp = succ;
        if (succ->succ)
            succ->succ->prev = this;
        succ = succ->succ;
        free(tmp);
    }

    void remove() {
        if (prev)
            prev->succ = succ;
        if (succ)
            succ->prev = prev;
    }
};

// class List {
//     List_Node *dummy;
//     List_Node *tail;

// public:
//     List(): dummy(new List_Node()), tail(dummy) {}

// };

class LRUCache {
    int cnt;
    int cap;
    unordered_map<int, pair<int, List_Node*>> cache;
    List_Node* dummy;
    List_Node* tail;

public:
    LRUCache(int capacity): cnt(0), cap(capacity), dummy(new List_Node), tail(dummy) {
        
    }
    
    int get(int key) {
        if (!cache.count(key))
            return -1;
        List_Node *p = cache[key].second;
        if (p != tail) {
            p->remove();
            tail->insertAfter(p);
            tail = tail->succ;
        }
        cout << "After get(" << key << ")" << endl;
        print();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            if (cache[key].second == tail)
                tail = tail->prev;
            cache[key].second->remove();
            delete cache[key].second;
        } else if (cache.size() >= cap) {
            cache.erase(dummy->succ->key);
            if (dummy->succ == tail)
                tail = tail->prev;
            auto p = dummy->succ;
            dummy->succ->remove();
            delete p;
        }
        tail->succ = new List_Node(key, tail->succ, tail);
        tail = tail->succ;
        cache[key].first = value;
        cache[key].second = tail;
        cout << "After put(" << key << ", " << value << ")" << endl;
        print();
    }

    void print() {
        auto p = dummy->succ;
        while (p) {
            cout << p->key << " ";
            p = p->succ;
        }    
        cout << endl;
        for (const auto& [k, v] : cache)
            cout << "(" << k << ", " << v.first << ") ";
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    LRUCache* obj = new LRUCache(2);
    obj->get(2);
    obj->put(2, 6);
    obj->get(1);
    obj->put(1, 5);
    obj->put(1, 2);
    obj->get(1);
    obj->get(2);
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */