#include "usual.h"

class Solution {
public:
    bool asteroidsDestroyed(int mm, vector<int>& asteroids) {
        multiset<long long> s;
        for (const auto& m :asteroids) {
            s.insert(m);
        }
        long long mass = mm;
        while (!s.empty()) {
            auto p = s.upper_bound(mass);
            if (p == s.begin())
                return false;
            p = prev(p);
            mass += *p;
            s.erase(p);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
