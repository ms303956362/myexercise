# include <iostream>
# include "Sales_item.h"

int main()
{
    // 1_20
    // Sales_item item;
    // while (std::cin >> item)
    //     std::cout << item << std::endl;
    // return 0;

    // 1_21
    // Sales_item item1, item2;
    // std::cin >> item1 >> item2;
    // if (item1.isbn() == item2.isbn()){
    //     std::cout << item1 + item2 << std::endl;
    //     return 0;
    // } else {
    //     std::cerr << "ISBN not same" << std::endl;
    //     return -1;
    // }

    // 1_5_22
    Sales_item item, item_prev, item_sum;
    if (std::cin >> item_prev) {
        item_sum = item_prev;
        while (std::cin >> item) {
            if (item.isbn() == item_prev.isbn()) {
                item_sum += item;
                item_prev = item;
            } else {
                std::cout << item_sum << std::endl;
                item_prev = item;
                item_sum = item;
            }
        }
        std::cout << item_sum << std::endl;
    }
    return 0;

    // // 1_5_23
    // Sales_item item, item_prev;
    // if (std::cin >> item_prev){
    //     int cnt = 1;
    //     while (std::cin >> item){
    //         if (item_prev.isbn() == item.isbn()){
    //             cnt++;
    //         } else {
    //             std::cout << "ISBN: " << item_prev.isbn() << " counts: " << cnt << std::endl;
    //             cnt = 1;
    //             item_prev = item;
    //         }
    //     }
    //     std::cout << "ISBN: " << item_prev.isbn() << " counts: " << cnt << std::endl;
    // }
    // return 0;
}
