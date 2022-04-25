#include "usual.h"

class Bitset {
    vector<int> a;
    int sz;
    int cnt;
    bool turn;

public:
    Bitset(int size): sz(size), a(size), cnt(0), turn(false) {

    }
    
    void fix(int idx) {
        if (turn) {
            if (a[idx] == 1) {
                --cnt;
            }
            a[idx] = 0;
        } else {
            if (a[idx] == 0) {
                ++cnt;
            }
            a[idx] = 1;
        }
    }
    
    void unfix(int idx) {
        if (!turn) {
            if (a[idx] == 1) {
                --cnt;
            }
            a[idx] = 0;
        } else {
            if (a[idx] == 0) {
                ++cnt;
            }
            a[idx] = 1;
        }
    }
    
    void flip() {
        turn = !turn;
    }
    
    bool all() {
        return turn ? (cnt == 0) : (cnt == sz);
    }
    
    bool one() {
        return turn ? (cnt < sz) : (cnt > 0);
    }
    
    int count() {
        return turn ? (sz - cnt) : (cnt);
    }
    
    string toString() {
        string ret;
        for (int i = 0; i < sz; ++i) {
            if (turn) {
                ret.push_back((1 - a[i]) + '0');
            } else {
                ret.push_back(a[i] + '0');
            }
        }
        return ret;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

int main(int argc, char const *argv[])
{
    
    return 0;
}
