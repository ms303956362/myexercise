#include "usual.h"

class DataStream {
    int v, k;
    int cnt;
public:
    DataStream(int value, int k): v(value), k(k), cnt(0) {

    }
    
    bool consec(int num) {
        if (num == v) {
            ++cnt;
        } else {
            cnt = 0;
        }
        return cnt >= k;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
