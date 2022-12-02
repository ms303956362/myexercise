#include <iostream>

using namespace std;

int n;
int money[100005];

int dfs(int i) {
    if (i > n) {
        return 0;
    }
    return money[i] + max(dfs(2 * i), dfs(2 * i + 1));
}

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> money[i];
    }
    cout << dfs(1) << endl;
    return 0;
}
