#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(3));
    a[0][0] = a[n][0] = a[0][1] = a[n][1] = a[0][2] = a[n][2] = 1;
    vector<pair<char, int>> op(m);
    for (int i = 0; i < m; ++i) {
        cin >> op[i].first;
    }
    for (int i = 0; i < m; ++i) {
        cin >> op[i].second;
    }
    vector<int> max_s(3, n);
    for (int i = 0; i < m; ++i) {
        char dir = op[i].first;
        int s = op[i].second;
        a[s][dir - 'x'] = 1;
        int last = 0, max_dis = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i][dir - 'x'] == 1) {
                max_dis = max(max_dis, i - last);
                last = i;
            }
        }
        max_s[dir - 'x'] = max_dis;
        int max_v = 1;
        for (int j = 0; j < 3; ++j) {
            max_v *= max_s[j];
        }
        cout << max_v << endl;
    }
    return 0;
}
