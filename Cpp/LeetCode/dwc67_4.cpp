#include "usual.h"

class SORTracker {
    int i;
    set<pair<int, string>>::iterator ptr;
    set<pair<int, string>> m;

public:
    SORTracker(): i(0), ptr(m.end()) {

    }
    
    void add(string name, int score) {
        auto p = make_pair(-score, name);
        m.insert(p);
        if (ptr == m.end()) {
            ptr = prev(m.end());
        } else {
            if (p < *ptr) {
                ptr = prev(ptr);
            }
        }
    }
    
    string get() {
        string ans = ptr->second;
        ptr = next(ptr);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
