#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;

int main(int argc, char const *argv[])
{
    // 8.10
    vector<string> text;
    ifstream ifs("data/sstream");
    string line;
    while(getline(ifs, line)){
        text.push_back(line);
    }
    for (auto l : text)
    {
        istringstream iss(l);
        string s;
        while (iss >> s){
            cout << s << endl;
        }
    }

    return 0;
}
