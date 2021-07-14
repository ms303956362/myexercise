#include "usual.h"

class FindSumPairs {
    multiset<int> s;
    vector<int> n1, n2;
    unordered_map<int, int> cnt;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end()), s(nums2.begin(), nums2.end()) {
        cnt.clear();
        for (const auto& num : nums2) {
            if (cnt.count(num))
                ++cnt[num];
            else
                cnt[num] = 1;
        }
    }
    
    void add(int index, int val) {
        auto p = s.lower_bound(n2[index]);
        s.erase(p);
        s.insert(n2[index] + val);
        --cnt[n2[index]];
        n2[index] += val;
        if (cnt.count(n2[index]))
            ++cnt[n2[index]];
        else
            cnt[n2[index]] = 1;
    }
    
    int count(int tot) {
        int ans = 0;
        for (const auto& num : n1) {
            auto p = s.lower_bound(tot - num);
            if (p != s.end() && *p == tot - num)
                ans += cnt[*p];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
