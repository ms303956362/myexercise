# include <iostream>

int main(){
    //错误：std::cin >> int input_value;   原因：
    int input_value;
    std::cin >> input_value;
    //错误：int i = {3.14};
    int i = 3.14;
    //错误：double salary = wage = 9999.99;   //原因：wage未声明变量
    double wage;
    double salary = wage = 9999.99;
    std::cout << salary << " " << wage;
    //变量定义可以只有_
    int _;
    return 0;
}