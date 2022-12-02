#include "usual.h"

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int en = initialEnergy, ex = initialExperience;
        int ans = 0;
        for (const auto& e : energy) {
            if (en <= e) {
                ans += e + 1 - en;
                en = e + 1;
            }
            en -= e;
        }
        for (const auto& e : experience) {
            if (ex <= e) {
                ans += e + 1 - ex;
                ex = e + 1;
            }
            ex += e;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
