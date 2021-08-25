#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    unordered_map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
        idx[in[i]] = i;
    }
    int lp = 0, hp = n - 1, li = 0;
    while (lp < hp) {
        int m = idx[pre[lp]] - li;
        if (m > 0) {
            hp = lp + m;
            ++lp;
        } else {
            lp += m + 1;
            ++li;
        }
    }
    cout << pre[lp];
    return 0;
}
