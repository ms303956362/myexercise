// IO
#include <iostream>
#include <iomanip>      // std::setprecision
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

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    bool ok = false;
    if (a[0] == a[n - 1]) {
        ok = true;
        ll sum = 0;
        for (int i = 1; i < n - 1; ++i) {
            sum += a[i] * i;
        }
        b[n - 1] += 1e12;
        b[0] += -1e12;
        if (a[0] == 1) {
            if (sum > 0) {
                b[n - 1] -= sum;
            } else {
                b[0] -= sum;
            }
        } else {
            if (sum > 0) {
                b[0] += sum;
            } else {
                b[n - 1] += sum;
            }
        }
    }
    if (!ok) {
        ll pre = 0, i = 0;
        while (i < n) {
            pre += a[i];
            if (pre * a[n - 1] > 0) {
                break;
            }
            ++i;
        }
        if (i < n) {
            ok = true;
            ll sum = 0;
            for (int j = 0; j <= i; ++j) {
                b[j] = -1e12 + j;
                sum += a[j] * j;
            }
            for (int j = i + 1; j < n - 1; ++j) {
                b[j] = j;
                sum += a[j] * j;
            }
            b[n - 1] += 1e12;
            if (a[n - 1] == 1) {
                if (sum > 0) {
                    b[n - 1] -= sum;
                } else {
                    b[i] -= sum;
                }
            } else {
                if (sum > 0) {
                    b[i] += sum;
                } else {
                    b[n - 1] += sum;
                }
            }
        }
    }
    if (!ok) {
        ll suf = 0, i = n - 1;
        while (i >= 0) {
            suf += a[i];
            if (suf * a[0] > 0) {
                break;
            }
            --i;
        }
        if (i >= 0) {
            ok = true;
            ll sum = 0;
            for (int j = n - 1; j >= i; --j) {
                b[j] = 1e12 - (n - 1 - j);
                sum += a[j] * -(n - 1 - j);
            }
            for (int j = i - 1; j > 0; --j) {
                b[j] = n - 1 - j;
                sum += a[j] * (n - 1 - j);
            }
            b[0] += -1e12;
            if (a[0] == 1) {
                if (sum > 0) {
                    b[i] -= sum;
                } else {
                    b[0] -= sum;
                }
            } else {
                if (sum > 0) {
                    b[0] += sum;
                } else {
                    b[i] += sum;
                }
            }
        }
    }
    if (ok) {
        cout << "Yes" << '\n';
        for (int i = 0; i < n; ++i) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0;
}
