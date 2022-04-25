#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solve(vector<int>& values) {
    int n = values.size();
    priority_queue<int> q;
    q.push(values[0] + 0);
    int ans = INT_MIN;
    for (int j = 1; j < n; ++j) {
        int max_sum = q.top();
        ans = max(ans, max_sum + values[j] - j);
        q.push(values[j] + j);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a) << endl;
    return 0;
}
