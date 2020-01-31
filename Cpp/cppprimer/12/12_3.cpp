#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;

#include "MyTextQuery.h"

void runQueries_directly(ifstream& infile){
    MyTextQuery tq(infile);
    while (true){
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s=="q")
            break;
        print(cout, tq.query(s));
    }
}


int main(int argc, char const *argv[])
{
    // 12.27
    ifstream infile("data/storyDataFile");
    runQueries_directly(infile);
    return 0;
}
