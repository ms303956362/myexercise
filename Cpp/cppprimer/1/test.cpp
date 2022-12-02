#include <iostream>
#include <functional>

class Defer {
    // func
    std::function<void(void)> f_;

public:
    Defer(std::function<void(void)>& f): f_(f) {}
    ~Defer() {
        f_();
    }
};

void test() {
    int a = 0;
    std::function<void(void)> f = [&]() {
        std::cout << "[end]: a=" << a << std::endl;
    };
    Defer d{f};
    std::cout << "[begin] a=" << a << std::endl;
    a = a + 1;
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
