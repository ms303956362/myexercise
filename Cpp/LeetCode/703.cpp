#include "usual.h"
class Int {
public:
    int n;
    Int(int i) : n(i) {}
};

bool operator<(const Int& i1, const Int& i2) {
    return i1.n > i2.n;
}

class KthLargest {
public:
    KthLargest(int kth, vector<int>& nums): k(kth) {
        for (auto& n : nums) {
            s.insert(n);
        }
    }
    
    int add(int val) {
        s.insert(val);
        int cnt = 0, res = 0;
        for (auto& n : s) {
            if (cnt++ == k) {
                res = n.n;
                break;
            }
        }
        return res;
    }

private:
    int k;
    multiset<Int> s;
};

int main(int argc, char const *argv[])
{
    int k = 3;
    vector<int> nums{4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);
    param_1 = obj->add(5);
    param_1 = obj->add(10);
    param_1 = obj->add(9);
    param_1 = obj->add(4);
    return 0;
}
