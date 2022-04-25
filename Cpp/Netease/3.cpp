#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int cnt_even = 0, cnt_odd = 0;
    int l = 1, total = 0, step = 0;
    while (total < n) {
        if (step % 2 == 0) {
            cnt_even += min(l, n - total);
        } else {
            cnt_odd += min(l, n - total);
        }
        ++step;
        total += l;
        l *= 2;
    }
    bool even_level_first = (cnt_even <= cnt_odd);
    step = 0;
    l = 1;
    total = 0;
    int last_even = 2, last_odd = 1;
    vector<int> ans(n);
    while (total < n) {
        if ((step % 2 == 0 && even_level_first) || (step % 2 == 1 && !even_level_first)) {
            for (int i = total; i < min(total + l, n); ++i) {
                ans[i] = last_even;
                last_even += 2;
            }
        } else {
            for (int i = total; i < min(total + l, n); ++i) {
                if (last_odd > n) {
                    ans[i] = last_even;
                    last_even += 2;
                } else {
                    ans[i] = last_odd;
                    last_odd += 2;
                }
            }
        }
        ++step;
        total += l;
        l *= 2;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
