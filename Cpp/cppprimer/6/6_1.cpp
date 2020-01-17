#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
    // 6.3
    // cout << fact(5) << endl;
    // cout << fact(1) << endl;
    // cout << fact(0) << endl;

    // 6.4
    // unsigned int i;
    // cout << "Enter an unsigned integer: ";
    // while (cin >> i){
    //     cout << "Fact of " << i << ": " << fact(i) << endl;
    //     cout << "Enter an unsigned integer: ";
    // }

    // 6.5
    // cout << abs(3) << endl;
    // cout << abs(-1) << endl;
    // cout << abs(0) << endl;

    // 6.6
    // for (int i = 0; i != 10; ++i){
    //     cout << "add " << i << " sum: " << add(i) << endl;
    // }

    // 6.7
    for (int i = 0; i != 10; ++i){
        cout << "Cnt: " << inc() << endl;
    }

    return 0;
}

unsigned int fact(unsigned int n){
    unsigned int p = 1;
    for (unsigned int i = 1; i <= n; ++i){
        p *= i;
    }
    return p;
}

double abs(double x){
    return x < 0 ? -x : x;
}

int add(int n){
    static int sum = 0;
    sum += n;
    return sum;
}

int inc(){
    static int cnt = 0;
    return cnt++;
}
