#include "usual.h"

class SmallestInfiniteSet {
    vector<bool> has;
public:
    SmallestInfiniteSet(): has(1005, true) {

    }
    
    int popSmallest() {
        for (int i = 1; i <= 1001; ++i) {
            if (has[i]) {
                has[i] = false;
                return i;
            }
        }
        return -1;
    }
    
    void addBack(int num) {
        has[num] = true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
