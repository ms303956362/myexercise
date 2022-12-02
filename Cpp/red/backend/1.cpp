#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, id;
    cin >> n >> m >> id;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            sum += x;
        }
        v.emplace_back(sum, -i - 1);
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < n; ++i) {
        if (-v[i].second == id) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
