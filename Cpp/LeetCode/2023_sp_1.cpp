#include "usual.h"

class Solution {
public:
    vector<int> supplyWagon(vector<int>& supplies) {
        int l = supplies.size();
        while (supplies.size() > l / 2) {
            int min_sum = 0x3f3f3f3f, n = supplies.size(), idx = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (supplies[i] + supplies[i + 1] < min_sum) {
                    min_sum = supplies[i] + supplies[i + 1];
                    idx = i;
                }
            }
            vector<int> tmp;
            for (int i = 0; i < idx; ++i) {
                tmp.push_back(supplies[i]);
            }
            tmp.push_back(supplies[idx] + supplies[idx + 1]);
            for (int i = idx + 1; i < n; ++i) {
                tmp.push_back(supplies[i]);
            }
            supplies = tmp;
        }
        return supplies;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
