#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        lines.emplace_back(a, b);
    }
    int ans = 0;
    vector<int> color(n);
    for (int s = 0; s < (1 << n); ++s) {
        vector<int> a1, a2;
        for (int i = 0; i < n; ++i) {
            if (s & (1 << i)) {
                color[i] = 0;
            } else {
                color[i] = 1;
            }
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (color[i] != color[j] && lines[i].first * lines[j].second != lines[j].first * lines[i].second) {
                    ++t;
                }
            }
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
