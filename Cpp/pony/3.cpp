#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // stack<string> s1, s2, s3, s4;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'p') {
            ++cnt1;
        } else if (s[i] == 'o') {
            if (cnt1 > 0) {
                --cnt1;
                ++cnt2;
            }
        } else if (s[i] == 'n') {
            if (cnt2 > 0) {
                --cnt2;
                ++cnt3;
            }
        } else {
            if (cnt3 > 0) {
                --cnt3;
                ++cnt4;
            }
        }
    }
    cout << cnt4 << endl;
    return 0;
}
