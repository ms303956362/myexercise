#include <iostream>
#include <vector>
#include <functional>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> s, nums(2 * n);
    vector<int> vst(n);
    bool ok = true;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> nums[i];
        --nums[i];
    }
    for (int i = 0; i < 2 * n && ok; ++i) {
        int a = nums[i];
        if (vst[a]) {
            if (!s.empty() && s.back() == a) {
                // no conflict
                s.pop_back();
            } else {
                int m = s.size(), j = m - 1;
                while (j >= 0 && s[j] != a) {
                    if (!d.unite(s[j], a)) {
                        ok = false;
                        break;
                    }
                    --j;
                }
                if (!ok) {
                    break;
                }
                s.erase(s.begin() + j);
            }
        } else {
            s.push_back(a);
        }
        vst[a] = true;
    }
    if (ok) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}
