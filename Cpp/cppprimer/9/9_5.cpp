#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::invalid_argument;
using std::out_of_range;
using std::string;

#include <vector>
using std::vector;

#include <sstream>
using std::stringstream;

string& find_and_replace(string& s, const string& oldVal, const string& newVal){
    for (auto iter = s.begin(); std::distance(iter, s.end()) >= std::distance(oldVal.begin(), oldVal.end()); ++iter){
        if (string(iter, iter + oldVal.size()) == oldVal)
        {
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.begin(), newVal.end());
            iter += newVal.size() - 1;
        }
    }
    return s;
}

string& find_and_replace2(string& s, const string& oldVal, const string& newVal){
    string::size_type pos = 0;
    while ((pos = s.find(oldVal, pos)) != string::npos)
    {
        s.replace(pos, oldVal.size(), newVal);
        pos += newVal.size();
    }
    return s;
}

string& add_pre_post(string& s, const string& pre, const string& post){
    s.insert(s.begin(), pre.begin(), pre.end());
    s.append(post.begin(), post.end());
    return s;
}

string& add_pre_post2(string& s, const string& pre, const string& post){
    s.insert(0, pre);
    s.insert(s.size(), post);
    return s;
}

class Date{
public:
    Date(const string& s);
private:
    unsigned year;
    unsigned month;
    unsigned day;
};

int find_month(vector<string> mon, string s){
    for (decltype(mon.size()) i = 0; i != mon.size(); ++i){
        if (mon[i] == s){
            return i + 1;
        }
    }
    return 0;
}

Date::Date(const string& s){
    vector<string> mon{"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "Novemver", "Decmber"};
    vector<string> m{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    stringstream ss(s);
    string s_curr;
    int mon_find;
    ss >> s_curr;
    if ((mon_find = find_month(mon, s_curr)) != 0)
    {
        month = mon_find;
        ss >> s_curr;
        s_curr.pop_back();
        day = std::stoi(s_curr);
        ss >> s_curr;
        year = std::stoi(s_curr);
    }
    else if ((mon_find = find_month(m, s_curr)) != 0)
    {
        month = mon_find;
        ss >> s_curr;
        day = std::stoi(s_curr);
        ss >> s_curr;
        year = std::stoi(s_curr);
    } else {
        decltype(s_curr.begin()) first, second;
        bool is_first = true;
        for (auto iter = s_curr.begin(); iter != s_curr.end(); ++iter){
            if (*iter == '/'){
                if (is_first){
                    is_first = false;
                    first = iter;
                } else {
                    second = iter;
                    break;
                }
            }
        }
        try{
            month = std::stoi(string(s_curr.begin(), first));
            day = std::stoi(string(first + 1, second));
            year = std::stoi(string(second + 1, s_curr.end()));
        } catch(invalid_argument&) { 
            cerr << "invaild format" << endl;
        } catch(out_of_range&) {
            cerr << "invaild number" << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    // 9.41
    // vector<char> cv{'H', 'e', 'l', 'l', 'o'};
    // const size_t n = cv.size();
    // char cp[n];
    // for (size_t i=0;i!=n;++i){
    //     cp[i] = cv[i];
    // }
    // string s(cp, n);
    // cout << s << endl;

    // 9.43
    // string s("abc thodeftho");
    // cout << find_and_replace(s, "tho", "though") << endl;

    // 9.44
    // string s("abcthodefthoghi");
    // cout << find_and_replace2(s, "tho", "though") << endl;

    // 9.45
    // string s("John Wei");
    // cout << add_pre_post(s, "Mr.", " nb");

    // 9.46
    // string s("John Wei");
    // cout << add_pre_post2(s, "Mr.", " nb");

    // 9.47
    // string s("ab2c3d7R4E6");
    // string::size_type pos = 0;
    // cout << "numbers: ";
    // while ((pos=s.find_first_of("0123456789", pos)) != string::npos){
    //     cout << s[pos] << " ";
    //     ++pos;
    // }
    // cout << endl;
    // pos = 0;
    // cout << "letters: ";
    // while ((pos=s.find_first_not_of("0123456789", pos)) != string::npos){
    //     cout << s[pos] << " ";
    //     ++pos;
    // }
    // cout << endl;

    // 9.49
    // string middle("acemnorsuvwxz");
    // string word, word_max;
    // while (cin >> word){
    //     if (word.find_first_not_of(middle) == string::npos && word.size() > word_max.size()){
    //             word_max = word;
    //     }
    // }
    // cout << "max length word: "<< word_max <<"max length: " << word_max.size() << endl;

    // 9.50
    // vector<string> sv{"12", "-15"};
    // int sum = 0;
    // for (auto s : sv){
    //     sum += std::stoi(s);
    // }
    // cout << sum << endl;
    // vector<string> sfv{"3.14", "-5.13", "0x1F"};
    // float fsum = 0;
    // for (auto sf : sfv){
    //     fsum += std::stof(sf);
    // }
    // cout << fsum << endl;

    // 9.51
    Date d1("January 1, 1990");
    Date d2("1/1/1990");
    Date d3("Jan 1 1990");


    return 0;
}
