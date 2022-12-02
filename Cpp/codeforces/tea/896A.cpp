// IO
#include <iostream>
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

ll len1 = 34, len2 = 32, len3 = 2;
ll len[100005];

string f0("What are you doing at the end of the world? Are you busy? Will you save us?");
string s1("What are you doing while sending \""), s2("\"? Are you busy? Will you send \""), s3("\"?");

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    len[0] = 75;
    for (int i = 1; i < 100005; ++i) {
        len[i] = min(0x3f3f3f3f3f3f3f3f, len1 + len2 + len3 + 2 * len[i - 1]);
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        ll k;
        cin >> n >> k;
        --k;
        bool ok = false;
        for (int i = n; i > 0; --i) {
            if (k < len1) {
                cout << s1[k];
                ok = true;
                break;
            } else if (len1 <= k && k < len1 + len[i - 1]) {
                k -= len1;
            } else if (len1 + len[i - 1] <= k && k < len1 + len[i - 1] + len2) {
                cout << s2[k - (len1 + len[i - 1])];
                ok = true;
                break;
            } else if (len1 + len[i - 1] + len2 <= k && k < len1 + 2 * len[i - 1] + len2) {
                k -= len1 + len[i - 1] + len2;
            } else if (len1 + 2 * len[i - 1] + len2 <= k && k < len1 + 2 * len[i - 1] + len2 + len3) {
                cout << s3[k - (len1 + 2 * len[i - 1] + len2)];
                ok = true;
                break;
            } else {
                cout << ".";
                ok = true;
                break;
            }
        }
        if (!ok) {
            if (0 <= k && k < len[0]) {
                cout << f0[k];
            } else {
                cout << ".";
            }
        }
    }
    cout << endl;
    return 0;
}
