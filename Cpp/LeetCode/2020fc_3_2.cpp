#include "usual.h"

typedef unsigned long long ull;

struct LListNode {
    int data;
    struct LListNode *prev;
    struct LListNode *succ;
    LListNode() = default;
    LListNode(int e, struct LListNode* p, struct LListNode *s) : data(e), prev(p), succ(s) {}
    struct LListNode * insertAsPred(int e) {
        struct LListNode * node = new LListNode(e, prev, this);
        if (prev) 
            prev->succ = node;
        prev = node;
        return node;
    }
};

typedef struct LListNode* Posi;

struct List {
    int sz;
    Posi header;
    Posi trailer;

    List() { init(); }
    void init() {
        header = new struct LListNode;
        trailer = new struct LListNode;
        header->succ = trailer;
        header->prev = nullptr;
        trailer->prev = header;
        trailer->succ = nullptr;
        sz = 0;
    }
    int size() { return sz; }
    Posi insertAsLast(int e) {
        ++sz;
        return trailer->insertAsPred(e);
    }

    Posi last() const { return trailer->prev; } // inline

    int remove(Posi p) {
        int e = p->data;
        p->prev->succ = p->succ;
        p->succ->prev = p->prev;
        delete p;
        --sz;
        return e;
    }
};

class Solution {
public:
    int minimumOperations(string leaves) {
        List l;
        multimap<int, ull> mp;
        unordered_set<ull> s;
        int ans = 0, n = leaves.size();
        if (leaves[0] == 'y') {
            leaves[0] = 'r';
            ++ans;
        }
        if (leaves[n - 1] == 'y') {
            leaves[n - 1] = 'r';
            ++ans;
        }
        int cnt = 1;
        char c = 'r';
        bool first = true;
        for (int i = 1; i != n; ++i) {
            if (leaves[i] != c) {
                l.insertAsLast(cnt);
                s.insert((ull)(l.last()));
                if (first)
                    first = false;
                else
                    mp.emplace(cnt, (ull)(l.last()));
                cnt = 1;
                c = leaves[i];
            } else {
                ++cnt;
            }
        }
        l.insertAsLast(cnt);
        s.insert((ull)(l.last()));
        if (l.size() == 1)
            return ans + 1;
        if (l.size() == 3)
            return ans;
        while (l.size() > 3) {
            Posi p = (Posi)(mp.begin()->second);
            mp.erase(mp.begin());
            if (s.count((ull)p) == 0) {
                continue;
            }
            ans += p->data;
            auto pn = p->succ, pp = p->prev;
            p->data += pn->data + pp->data;
            l.remove(pn);
            s.erase((ull)pn);
            l.remove(pp);
            s.erase((ull)pp);
            if (p->prev != l.header && p->succ != l.trailer)
                mp.emplace(p->data, (ull)p);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minimumOperations("ryryyyyyyrrrrryyyyyrrrrr") << endl;
    return 0;
}