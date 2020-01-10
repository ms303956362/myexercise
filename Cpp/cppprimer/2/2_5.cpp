# include <iostream>

int main(int argc, char const *argv[])
{
    // 2.34
    // int i = 0, &r = i;
    // auto a = r;
    // const int ci = i, &cr = ci;
    // auto b = ci;
    // auto c = cr;
    // auto d = &i;
    // auto e = &ci;
    // auto &g = ci;
    // a = 42;
    // std::cout << "a is " << a << std::endl;
    // b = 42;
    // std::cout << "b is " << b << std::endl;
    // c = 42;
    // std::cout << "c is " << c << std::endl;
    // d = 42;   //d是int*，不能被int赋值
    // std::cout << "d is " << d;
    // e = 42;   //e是const int*，不能被int赋值
    // std::cout << "e is " << e;
    // g = 42;   //g是const int的引用，不能被赋值
    // std::cout << "g is " << g;

    // 2.35
    // const int ii = 42;
    // auto j = ii;
    // const auto &k = ii;
    // auto *p = &ii;
    // const auto j2 = ii, &k2 = ii;
    // return 0;

    // 2.37
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    std::cout << a << b << c << d << std::endl;
}
