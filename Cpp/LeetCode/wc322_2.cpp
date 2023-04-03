#include "usual.h"

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long sum = skill[0] + skill[n - 1];
        long long ans = (long long)skill[0] * skill[n - 1];
        for (int i = 1, j = n - 2; i < j; ++i, --j) {
            if (skill[i] + skill[j] != sum) {
                return -1;
            }
            ans += (long long)skill[i] * skill[j];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
