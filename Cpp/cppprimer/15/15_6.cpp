#include <iostream>
#include <utility>
using std::cout;
using std::endl;
#include "MyQuote.h"

int main(int argc, char const *argv[])
{
    // 15.26
    cout << "========== mbq2(mbq1) ============" << endl;
    MyBulkQuote mbq1("0-399-82477-1", 45.39, 3, 0.8), mbq2(mbq1), mbq3;
    cout << "========== mbq3 = mbq2 ============" << endl;
    mbq3 = mbq2;
    mbq2.debug(cout) << endl;
    mbq3.debug(cout) << endl;
    cout << "========== mbq4(std::move(mbq1)) ============" << endl;
    MyBulkQuote mbq4(std::move(mbq1)), mbq5;
    mbq1.debug(cout) << endl;
    mbq4.debug(cout) << endl;
    cout << "========== mbq5 = std::move(mbq2); ============" << endl;
    mbq5 = std::move(mbq2);
    mbq2.debug(cout) << endl;
    mbq5.debug(cout) << endl;
    return 0;
}
