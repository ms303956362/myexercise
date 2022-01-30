#include "usual.h"

class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.size();
        if (n == 1) {
            if (street[0] == 'H')
                return -1;
            else
                return 0;
        } else {
            if (street[0] == 'H' && street[1] == 'H' || street[n - 1] == 'H' && street[n - 2] == 'H')
                return -1;
            for (int i = 1; i <= n - 2; ++i) {
                if (street[i] == 'H' && street[i - 1] == 'H' && street[i + 1] == 'H')
                    return -1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (street[i] != 'H')
                continue;
            if (i + 1 == n || street[i + 1] == 'H') {
                if (street[i - 1] != 'B') {
                    street[i - 1] = 'B';
                    ++ans;
                }
            } else {
                if (i == 0 || street[i - 1] != 'B') {
                    street[i + 1] = 'B';
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
