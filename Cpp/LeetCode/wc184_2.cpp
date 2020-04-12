#include "usual.h"

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        list<int> vm;
        vector<int> res;
        for (int i = 0; i != m; ++i) {
            vm.push_back(i + 1);
        }
        for (auto& q : queries) {
            decltype(vm.begin()) p;
            int idx = 0;
            for (p = vm.begin(); p != vm.end(); ++p) {
                if (*p == q)
                    break;
                ++idx;
            }
            res.push_back(idx);
            vm.erase(p);
            vm.push_front(q);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int m = 5;
    vector<int> v{3, 1, 2, 1};
    vector<int> res = Solution().processQueries(v, m);
    return 0;
}
