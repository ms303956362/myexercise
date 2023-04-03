#include "usual.h"

class Solution {
public:
    int passThePillow(int n, int time) {
        int id = 1, dir = 1;
        for (int t = 0; t < time; ++t) {
            if (id == n) {
                dir = -1;
            } else if (id == 1) {
                dir = 1;
            }
            id += dir;
        }
        return id;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
