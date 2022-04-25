#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<vector<int>> sum_s(5005);
    int a[25];
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total += a[i];
    }
    for (int s = 0; s < (1 << n); ++s) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                sum += a[i];
            }
        }
        sum_s[sum].push_back(s);
    }
    int ans = 0;
    bool ok = false;
    for (int sum = total; sum >= 0 && !ok; --sum) {
        if (sum % 2 == 1) {
            continue;
        }
        for (const auto& s1 : sum_s[sum]) {
            for (const auto& s2 : sum_s[sum / 2]) {
                if ((s1 | s2) == s1) {
                    ok = true;
                    ans = sum / 2;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
    }
    if (ok) {
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
