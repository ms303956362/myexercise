#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include "MyQuote.h"

int main(int argc, char const *argv[])
{
    // 15.15
    MyBulkQuote mbq("0-399-82477-1", 45.39, 3, 0.8);
    mbq.debug(cout) << endl;
    print_total(cout, mbq, 5);

    // // 15.16
    MyBulkQuotemax mbqm("0-201-78345-X", 25.00, 2, 5, 0.7);
    mbqm.debug(cout) << endl;
    print_total(cout, mbqm, 1);
    print_total(cout, mbqm, 3);
    print_total(cout, mbqm, 6);

    // 15.17
    // MyDiscQuote mdq("0-399-82477-1", 45.39, 3, 0.8);

    return 0;
}
