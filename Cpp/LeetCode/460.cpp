#include "usual.h"

// class LFUCache {
// private:
//     unordered_map<int, int> cache;
//     unordered_map<int, int> cnt;
//     unordered_map<int, int> last_time;
//     int size;
//     int cap;
//     int time;

// public:
//     LFUCache(int capacity): size(0), cap(capacity), time(0) {

//     }
    
//     int get(int key) {
//         if (cap == 0)
//             return -1;
//         auto p = cache.find(key);
//         if (p != cache.end()) {
//             last_time[key] = time++;
//             ++cnt[key];
//             return p->second;
//         }
//         else
//             return -1;
//     }
    
//     void put(int key, int value) {
//         if (cap == 0)
//             return;
//         auto p = cache.find(key);
//         if (p == cache.end()) { // 未找到key
//             if (size < cap) // size没超过cap
//                 ++size;
//             else { // size等于cap
//                 decltype(cache.begin()) lfu_it = cache.begin();
//                 int lfu_cnt = cnt[lfu_it->first], lfu_last = last_time[lfu_it->first];
//                 int it_cnt, it_last;
//                 for (auto it = cache.begin(); it != cache.end(); ++it) {
//                     it_cnt = cnt[it->first];
//                     it_last = last_time[it->first];
//                     if (it_cnt < lfu_cnt || (it_cnt == lfu_cnt && it_last < lfu_last)) {
//                         lfu_it = it;
//                         lfu_cnt = it_cnt;
//                         lfu_last = it_last;
//                     }
//                 }
//                 cnt.erase(lfu_it->first);
//                 last_time.erase(lfu_it->first);
//                 cache.erase(lfu_it);
//             }
//         }
//         last_time[key] = time++;
//         cnt[key] = 0;
//         cache[key] = value;
//     }
// };

struct Node {
    int key;
    int val;
    int cnt;
    int time;
    Node (int k=0, int v=0, int t=0, int c = 0) : key(k), val(v), cnt(c), time(t) {}
    // Node (const Node& rn) : key(rn.key), val(rn.val), cnt(rn.cnt), time(rn.time) {}
    // Node& operator=(const Node& rn) {
    //     key = rn.key;
    //     val = rn.val;
    //     cnt = rn.cnt;
    //     time = rn.time;
    //     return *this;
    // }
    // Node (const Node&& rn) : key(std::move(rn.key)), val(std::move(rn.val)), cnt(std::move(rn.cnt)), time(std::move(rn.time)) {}
};

bool operator<(const Node& ln, const Node& rn) {
    return ln.cnt < rn.cnt || (ln.cnt == rn.cnt && ln.time < rn.time);
}

class LFUCache {
private:
    unordered_map<int, Node> cache;
    set<Node> s;
    int size;
    int cap;
    int clock;

public:
    LFUCache(int capacity): size(0), cap(capacity), clock(0) {

    }
    
    int get(int key) {
        if (cap == 0)
            return -1;
        auto p = cache.find(key);
        if (p != cache.end()) { // 找到
            // 删除set中旧节点
            s.erase(p->second);
            // 更新map中节点
            p->second.time = clock++;
            ++p->second.cnt;
            // 插入更新后节点到set
            s.insert(p->second);
            return p->second.val;
        } else { // 未找到
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cap == 0)
            return;
        auto p = cache.find(key);
        if (p == cache.end()) { // 未找到key
            if (size < cap)
                ++size;
            else {
                cache.erase(s.begin()->key);
                s.erase(s.begin());
            }
            Node tmp = Node(key, value, clock++);
            cache[key] = tmp;
            s.insert(tmp);
        } else { // 找到key
            // 删
            s.erase(p->second);
            // 改
            p->second.time = clock++;
            ++p->second.cnt;
            // 增
            s.insert(p->second);
        }
    }
};

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
    return 0;
}
