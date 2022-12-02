#include <iostream>
#include <queue>
using namespace std;

int a[100005];

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    deque<int> q;
    for (int i = n - 1; i >= 0; --i) {
        q.push_back(a[i]);
        q.push_back(q.front());
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
    }
    while (!q.empty()) {
        cout << q.back() << " ";
        q.pop_back();
    }
    cout << endl;
    return 0;
}
