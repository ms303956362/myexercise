#include <iostream>
#include <string>
using namespace std;

istream& read_reset(istream& is){
    string s;
    while (is >> s){
        cout << s << " ";
    }
    cout << endl;
    is.clear();
    return is;
}

int main(int argc, char const *argv[])
{
    // 8.1
    if(read_reset(cin))
        cout << "test success" << endl;
    else
        cout << "test fail" << endl;

    return 0;
}
