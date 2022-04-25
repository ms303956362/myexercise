#include "usual.h"

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int x = 0; x <= 200; ++x) {
            for (int y = 0; y <= 200; ++y) {
                bool ok = false;
                for (const auto& c : circles) {
                    int xc = c[0], yc = c[1], r = c[2];
                    if ((x - xc) * (x - xc) + (y - yc) * (y - yc) <= r * r) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
