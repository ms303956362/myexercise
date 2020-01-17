#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;

class Window_mgr{
public:
    void clear(vector<Screen>::size_type i);
private:
    vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen{
    friend void Window_mgr::clear(vector<Screen>::size_type i);

public:
    using pos = string::size_type;
    // 构造函数
    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' '){};
    Screen(pos h, pos w, char ch) : height(h), width(w), contents(h * w, ch){};
    // 成员函数
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &set(pos r, pos c, char ch);
    Screen &display(ostream &os);
    const Screen &display(ostream &os) const;

private:
    pos height = 0;
    pos width = 0;
    pos cursor = 0;
    string contents;
    void do_display(ostream &os) const;
};

inline
char Screen::get(pos r, pos c) const{
    return contents[r * width + c];
}

inline
Screen& Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline
Screen& Screen::set(char ch){
    contents[cursor] = ch;
    return *this;
}

inline
Screen& Screen::set(pos r, pos c, char ch){
    contents[r * width + c] = ch;
    return *this;
}

Screen& Screen::display(ostream& os){
    do_display(os);
    return *this;
}

const Screen& Screen::display(ostream& os) const{
    do_display(os);
    return *this;
}

void Screen::do_display(ostream& os) const{
    for (auto pr = contents.begin(); pr != contents.end();pr += width){
        for (auto pc = pr; pc != pr + width; ++pc){
            cout << *pc;
        }
        cout << endl;
    }
}

// 7.31
class Y;
class X{
    Y *py=nullptr;
};
class Y{
    X x;
};

void Window_mgr::clear(vector<Screen>::size_type i){
    screens[i].contents = string(screens[i].height * screens[i].width, ' ');
}

int main(int argc, char const *argv[])
{
    // 7.24
    // Screen s0;
    // cout << s0.get() << endl;
    // Screen s1(2, 3);
    // cout << s1.get(1, 1) << endl;
    // Screen s2(2, 2, '*');
    // cout << s2.get(1, 2) << endl;
    // s2 = s1;
    // cout << s2.get(2, 3) << endl;

    // 7.27
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    myScreen.display(cout);
    return 0;
}
