#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, m;
    string a, b;
    vector<int> cnt(26);
    cin >> n >> m;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i] - 'a'];
    }
    int i = 0, j = 0, ans = 0;
    while (j < m) {
        char c = b[j] - 'a';
        --cnt[c];
        while (i <= j && cnt[c] < 0) {
            ++cnt[b[i] - 'a'];
            ++i;
        }
        ans += j - i + 1;
        ++j;
    }
    printf("%d\n", ans);
    return 0;
}
