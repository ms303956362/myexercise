#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class HasPtr{
private:
    std::string *ps;
    int i;

public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0){};
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i){};
    HasPtr &operator=(const HasPtr& rhp);
    ~HasPtr() { delete ps; }
};

HasPtr& HasPtr::operator=(const HasPtr& rhp) {
    delete ps;
    ps = new std::string(*rhp.ps);
    i = rhp.i;
    return *this;
}

struct X{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X& x) {
        std::cout << "X& operator=(X&)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

X f(X& x){
    return x;
}

int main(int argc, char const *argv[])
{
    // 13.5
    // HasPtr hp1("hello"), hp2 = hp1;

    // 13.8
    // HasPtr hp1("hello"), hp2;
    // hp2 = hp1;
    
    // 13.11
    // HasPtr hp("hello");
    
    // 13.13
    cout << "direct and copy initlization" << endl;
    X x1, x2(x1);
    cout << "copy assignment" << endl;
    x2 = x1;
    cout << "unref and ref parameter delivery" << endl;
    x2 = f(x1);
    cout << "dynamic allocation" << endl;
    X *px1 = new X;
    *px1 = x1;
    cout << "use vector<X>" << endl;
    vector<X> xv;
    xv.push_back(x1);
    cout << "destroy memory" << endl;
    delete px1;
    return 0;
}
