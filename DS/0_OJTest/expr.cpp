#include <iostream>
using std::cin;
using std::cout;

int main(int argc, char const *argv[])
{
    long long a, b, res;
    char op;
    cin >> a >> op >> b;
    switch (op)
    {
    case '+':
        res = a + b;
        break;
    case '-':
        res = a - b;
        break;
    default:
        res = a * b;
        break;
    }
    cout << res;
    return 0;
}
