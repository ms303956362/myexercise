// IO
#include <iostream>
#include <iomanip>      // std::setprecision
#include <sstream>
// ordered container
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
// associative-container
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
// algorithm
#include <algorithm>
#include <cmath>
// utility
#include <initializer_list>
#include <iterator>
#include <memory>
#include <utility>
// c
#include <cstdio>
#include <cstdlib>
#include <cstring>
// functional
#include <functional>

using namespace std;

using ll = long long;

#define MAX_NUM 200000
bool isPrime[ MAX_NUM + 10 ];

void prim(){
	for(int i = 2; i <= MAX_NUM; i++)
		isPrime[i] = 1;
	for(int i = 2; i <= MAX_NUM; i++){
		if( isPrime[i] )
			for(int j = 2 * i; j <= MAX_NUM; j += i)
				isPrime[j] = 0;
	}
}

void solve() {
    int n, x;
    cin >> n >> x;
    if (n % x != 0) {
        cout << -1 << "\n";
        return;
    }
    vector<int> a(n + 1);
    for (int i = 2; i <= n - 1; ++i) {
        a[i] = i;
    }
    a[1] = x;
    a[n] = 1;
    if (x == n) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    vector<int> factors;
    for (int i = 2; i <= n / x; ++i) {
        if (isPrime[i] && (n / x) % i == 0) {
            int tmp = n / x;
            while (tmp % i == 0) {
                factors.push_back(i);
                tmp /= i;
            }
        }
    }
    reverse(factors.begin(), factors.end());
    while (factors.size() > 1) {
        int f = factors.back();
        factors.pop_back();
        a[x] = x * f;
        x *= f;
    }
    a[x] = n;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    prim();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
