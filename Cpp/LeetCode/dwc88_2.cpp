#include "usual.h"

class LUPrefix {
    int n;
    set<int> st;
public:
    LUPrefix(int n): n(n) {
        for (int i = 1; i <= n; ++i) {
            st.insert(i);
        }
    }
    
    void upload(int video) {
        st.erase(video);
    }
    
    int longest() {
        if (st.empty()) {
            return n;
        }
        return *st.begin() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

int main(int argc, char const *argv[])
{
    
    return 0;
}
