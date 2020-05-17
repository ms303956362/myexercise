#include "PQ_Comp.h"

int main(int argc, char const *argv[])
{
    int a[11] = {31,23,28,19,15,11,6,8,16,13};
    PQ_Comp<int> q(a, 10);
    q.insert(42);
    return 0;
}
