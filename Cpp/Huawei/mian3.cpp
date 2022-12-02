#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& a) {
    int n = a.size(), i = 0, j = n - 1;
    int ans = 0;
    while (i < j) {
        ans = max(ans, min(a[i], a[j]) * (j - i));
        if (a[i] < a[j]) {
            ++i;
        } else {
            --j;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> a{1,8,6,2,5,4,8,3,7};
    cout << solve(a) << endl;
    return 0;
}
