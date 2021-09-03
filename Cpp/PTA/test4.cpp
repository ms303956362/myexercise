#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<int> cnt1(10), cnt2(10);
    for (const auto& c : s)
        ++cnt1[c - '0'];
    int n = s.size(), c = 0;
    string d(n + 1, '0');
    for (int i = n - 1; i >= 0;--i) {
        int tmp = (s[i] - '0') * 2 + c;
        ++cnt2[tmp % 10];
        d[n - i - 1] = tmp % 10 + '0';
        c = tmp / 10;
    }
    if (c == 1) {
        d[n] = '1';
        ++cnt2[1];
    } else {
        d.pop_back();
    }
    reverse(d.begin(), d.end());
    cout << (cnt1 == cnt2 ? "Yes" : "No") << endl;
    cout << d;
    return 0;
}
