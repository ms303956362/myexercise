#include <list>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class ListNode {
public:
    int first;
    int second;
    ListNode* prev;
    ListNode* next;
    ListNode(int k, int v): first(k), second(v), prev(nullptr), next(nullptr) {}
};

class List {
    int sz;
    ListNode *head, *tail;
public:
    List(): sz(0), head(new ListNode(-1, -1)), tail(new ListNode(-1, -1)) {
        head->next = tail;
        tail->prev = head;
    }

    void erase(ListNode* p) {
        if (sz == 0 || p == head || p == tail) {
            return;
        }
        p->next->prev = p->prev;
        p->prev->next = p->next;
        --sz;
    }

    void emplace_front(int key, int value) {
        ListNode* q = new ListNode(key, value), *p = head->next;
        head->next = q;
        p->prev = q;
        q->next = p;
        q->prev = head;
        ++sz;
    }

    int size() {
        return sz;
    }

    ListNode back() {
        return *tail->prev;
    }

    ListNode* begin() {
        return head->next;
    }

    void pop_back() {
        if (sz == 0) {
            return;
        }
        ListNode *p = tail->prev, *q = p->prev;
        tail->prev = q;
        q->next = tail;
        --sz;
    }
};


class LRUCache {
    int cap;
    List l;
    unordered_map<int, ListNode*> m;

public:
    LRUCache(int n): cap(n) {

    }

    int get(int key) {
        if (!m.count(key)) {
            return -1;
        }
        int val = m[key]->second;
        l.erase(m[key]);
        l.emplace_front(key, val);
        m[key] = l.begin();
        return val;
    }

    void put(int key, int value) {
        if (m.count(key)) {
            l.erase(m[key]);
            m.erase(key);
        }
        if (l.size() >= cap) {
            m.erase(l.back().first);
            l.pop_back();
        }
        l.emplace_front(key, value);
        m[key] = l.begin();
    }
};


int main(int argc, char const *argv[])
{
    LRUCache l(2);
    cout << l.get(1) << endl;
    l.put(1, 1);
    l.put(3, 3);
    cout << l.get(1) << endl;
    cout << l.get(3) << endl;
    l.put(4, 4);
    cout << l.get(1) << endl;
    return 0;
}
