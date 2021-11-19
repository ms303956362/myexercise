#include <string>
#include <vector>
#include <iostream>
using namespace std;

void inc(string& s) {
    int c = 0;
    for (auto p = s.rbegin(); p != s.rend(); ++p) {
        int num = *p - '0';
        *p = (num + c) % 10 + '0';
        c = (num + c) / 10;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }
        int ans = 0;
        for (int j = 1; j < n; ++j) {
            int n1 = v[j - 1].size(), n2 = v[j].size(), k = 0;
            if (n1 < n2 || (n1 == n2 && v[j - 1] < v[j]))
                continue;
            while (k < n1 && k < n2) {
                if (v[j - 1][k] != v[j][k])
                    break;
                ++k;
            }
            if (k < n2) {
                if (v[j][k] > v[j - 1][k]) {
                    ans += n1 - n2;
                    v[j] += string(n1 - n2, '0');
                } else {
                    ans += n1 - n2 + 1;
                    v[j] += string(n1 - n2 + 1, '0');
                }
            } else {
                if (n1 == n2) {
                    ans += 1;
                    v[j].push_back('0');
                }else if (v[j - 1].substr(k, n1 - k) == string(n1 - k, '9')) {
                    ans += n1 - k + 1;
                    v[j] += string(n1 - k + 1, '0');
                } else {
                    ans += n1 - k;
                    v[j] = v[j - 1];
                    inc(v[j]);
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
