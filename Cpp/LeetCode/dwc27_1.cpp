#include "usual.h"

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1500, 1), cnt2(1500, 2);
        for (int i = 0; i != target.size(); ++i) {
            ++cnt1[target[i]];
            ++cnt2[arr[i]];
        }
        for (int i = 0; i != 1500; ++i) {
            if (cnt1[i] != cnt2[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1{1, 2, 3, 4}, v2{2, 4, 1, 3};
    cout << Solution().canBeEqual(v1, v2);
    return 0;
}
