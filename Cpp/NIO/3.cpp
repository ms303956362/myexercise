#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    ll offset = 0, cnt_reverse = 0;
    for (int i = 0; i < m; ++i) {
        char op;
        cin >> op;
        if (op == 'A') {
            if (cnt_reverse % 2 == 0) {
                ++offset;
            } else {
                --offset;
            }
        } else {
            ++cnt_reverse;
        }
    }
    vector<int> nums;
    if (offset < 0) {
        offset += (-offset / n + 1) * n;
    }
    int start = (offset + n) % n;
    for (int i = 0; i < n; ++i) {
        nums.push_back(start + 1);
        start = (start + 1) % n;
    }
    if (cnt_reverse % 2 == 1) {
        reverse(nums.begin(), nums.end());
    }
    for (const auto& num : nums) {
        cout << num << endl;
    }
    return 0;
}
