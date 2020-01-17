#include <iostream>

using std::endl;
using std::cin;
using std::cout;

void swap1(int *pi1, int *pi2);
void reset(int &i);
void swap2(int &i1, int &i2);

int main(int argc, char const *argv[])
{
    // 6.10
    // int i1 = 2, i2 = 3;
    // swap(&i1, &i2);
    // cout << i1 << " " << i2 << endl;

    // 6.11
    // int i = 10;
    // reset(i);
    // cout << i << endl;

    // 6.12
    int i1 = 2, i2 = 3;
    swap2(i1, i2);
    cout << i1 << " " << i2 << endl;

    return 0;
}

void swap1(int *pi1, int *pi2){
    int tmp;
    tmp = *pi1;
    *pi1 = *pi2;
    *pi2 = tmp;
}

void reset(int &i){
    i = 0;
}

void swap2(int &i1, int &i2){
    int tmp;
    tmp = i1;
    i1 = i2;
    i2 = tmp;
}
