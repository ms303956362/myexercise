#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    auto check = [](int num)
    {
        int cnt = 0;
        while (num > 0) {
            if (num % 10 == 1) {
                ++cnt;
            }
            num /= 10;
        }
        return cnt >= 2;
    };
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num % 11 == 0 || check(num)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
