#include "usual.h"

class LFUCache {
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    unordered_map<int, int> data;
    list<int> l;
    unordered_map<int, list<int>::iterator> cnt;

public:
    LFUCache(int capacity): cap(capacity) {

    }
    
    int get(int key) {
        cout <<"get(" << key << ") = ";
        if (cap == 0 || !data.count(key)) {
            cout << -1 << endl;
            return -1;
        }
        int ret = data[key], c = m[key].first;
        // 更新计数值
        ++m[key].first;
        // 获取原位置、待插入位置
        auto p = m[key].second, q = cnt[c];
        if (cnt.count(c + 1)) {
            q = cnt[c + 1];
        }
        // 插入前更新cnt
        if (cnt[c] == p) {
            if (p == l.begin() || m[*prev(p)].first != c) {
                // p是第一个元素，或p的前一个元素计数值不为c
                cnt.erase(c);
            } else {
                cnt[c] = prev(p);
            }
        }
        // 更新在链表的位置，计数值为c+1的最后一个元素
        if (p != q) {
            // 删除原位置
            l.erase(p);
            p = l.insert(next(q), key);
        }
        // 插入后更新cnt和m[key]
        cnt[c + 1] = p;
        m[key].second = p;
        cout << ret << endl;
        return ret;
    }
    
    void put(int key, int value) {
        cout <<"put(" << key << ", " << value << ")" << endl;
        if (cap == 0)
            return;
        if (data.count(key)) {
            data[key] = value;
            get(key);
            return;
        }
        if (l.size() >= cap) {
            // 删除元素
            int del_key = l.front();
            if (l.begin() == cnt[m[del_key].first]) {
                cnt.erase(m[del_key].first);
            }
            l.pop_front();
            m.erase(del_key);
            data.erase(del_key);
        }
        // 插入key到计数值为1的位置
        auto p = l.begin();
        if (cnt.count(1)) {
            p = l.insert(next(cnt[1]), key);
        } else {
            l.push_front(key);
            p = l.begin();
        }
        data[key] = value;
        cnt[1] = p;
        m[key] = make_pair(1, p);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    
    LFUCache cache = LFUCache( 2 /* capacity (缓存容量) */ );
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // 返回 1
    cache.put(3, 3);    // 去除 key 2
    cout << cache.get(2) << endl;       // 返回 -1 (未找到key 2)
    cout << cache.get(3) << endl;       // 返回 3
    cache.put(4, 4);    // 去除 key 1
    cout << cache.get(1) << endl;       // 返回 -1 (未找到 key 1)
    cout << cache.get(3) << endl;       // 返回 3
    cout << cache.get(4) << endl;       // 返回 4

    LFUCache cache2 = LFUCache(2);
    cache2.put(2, 2);
    cache2.put(1, 1);
    // cout << cache2.get(1) << endl;       // 返回 1
    cache2.put(3, 3);    // 去除 key 2
    cout << cache2.get(2) << endl;       // 返回 -1 (未找到key 2)
    cout << cache2.get(3) << endl;       // 返回 3
    cache2.put(1, -2);
    cache2.put(4, 4);    // 去除 key 3
    cout << cache2.get(1) << endl;       // 返回 -2
    cout << cache2.get(3) << endl;       // 返回 -1 (未找到 key 3)
    cout << cache2.get(4) << endl;       // 返回 4
    return 0;
}