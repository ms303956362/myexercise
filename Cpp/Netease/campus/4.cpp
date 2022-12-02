#include <iostream>
#include <vector>
using namespace std;

int a[10005], diff[1000005], start[10005];
int finish[10005];

int main(int argc, char const *argv[])
{
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        start[i] = sum;
        sum += a[i] + 1;
    }
    sum = 0;
    for (int i = n - 1; i >= 0; --i) {
        finish[i] = w - sum;
        sum += a[i] + 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int l = max(start[i], finish[i] - a[i]), r = min(start[i] + a[i], finish[i]);
        for (int x = l; x < r; ++x) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (const auto& x : ans) {
        cout << x + 1 << " ";
    }
    cout << endl;
    return 0;
}
