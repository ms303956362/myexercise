#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    // 5.5
    // vector<string> levels = {"F", "D", "C", "B", "A", "A++"};
    // unsigned int grade;
    // string lettergrade;
    // while (cin >> grade){
    //     if (grade < 60)
    //         lettergrade = levels[0];
    //     else if (grade <= 100){
    //         lettergrade = levels[(grade - 50) / 10];
    //         if (grade < 100){
    //             if (grade % 10 > 7)
    //                 lettergrade += "+";
    //             else if (grade % 10 < 3)
    //                 lettergrade += "-";
    //         }
    //     }
    //     else{
    //         cout << "grade should be between 0 and 100 " << endl;
    //         continue;
    //     }
    //     cout << grade << " " << lettergrade << endl;
    // }

    // 5.6
    // vector<string> levels = {"F", "D", "C", "B", "A", "A++"};
    // unsigned int grade;
    // string lettergrade;
    // while (cin >> grade){
    //     if (grade > 100){
    //         cout << "grade should be between 0 and 100 " << endl;
    //         continue;
    //     }
    //     lettergrade = grade < 60 ? levels[0] : levels[(grade - 50) / 10];
    //     lettergrade += grade < 60 || grade == 100 ? "" : grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";
    //     cout << grade << " " << lettergrade << endl;
    // }

    // 5.9
    // unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    // char ch;
    // while (cin >> ch){
    //     if (ch=='a')
    //         ++aCnt;
    //     else if(ch == 'e')
    //         ++eCnt;
    //     else if (ch == 'i')
    //         ++iCnt;
    //     else if (ch == 'o')
    //         ++oCnt;
    //     else if (ch == 'u')
    //         ++uCnt;
    // }
    // cout << "Number of vowel a: \t" << aCnt << '\n'
    //      << "Number of vowel e: \t" << eCnt << '\n'
    //      << "Number of vowel i: \t" << iCnt << '\n'
    //      << "Number of vowel o: \t" << oCnt << '\n'
    //      << "Number of vowel u: \t" << uCnt << endl;

    // 5.10
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch){
        switch (ch)
        {
        case 'a': case 'A':
            ++aCnt;
            break;
        case 'e': case 'E':
            ++eCnt;
            break;
        case 'i': case 'I':
            ++iCnt;
            break;
        case 'o': case 'O':
            ++oCnt;
            break;
        case 'u': case 'U':
            ++uCnt;
            break;
        }
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;
    

    return 0;
}
