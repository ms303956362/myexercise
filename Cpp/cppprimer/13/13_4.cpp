#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "my_Folder.h"

int main(int argc, char const *argv[])
{
    // 13.37
    Folder f1;
    Message msg1("abc"), msg2("hello");
    msg1.save(f1);
    Message msg3(msg1);
    Folder f2(f1);
    msg3.remove(f2);
    msg2.save(f2);
    msg1 = msg2;
    Folder f3;
    f3 = f2;
    msg3.save(f3);
    msg3.save(f1);

    return 0;
}
