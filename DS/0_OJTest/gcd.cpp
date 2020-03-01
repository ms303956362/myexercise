#include <iostream>
using std::cin;
using std::cout;

void swap(long long& a, long long& b){
    long long tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, char const *argv[])
{
    long long a, b, r;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    cout << b;
    return 0;
}
