# include <iostream>
# include "2_6.h"

int main(int argc, char const *argv[])
{
    // 1.20
    // std::string bookID="";
    // int units_sold = 0;
    // double price = 0;
    // My_Sales_Data data;
    // while (std::cin >> data.bookID >> data.units_sold >> data.price){
    //     data.revenue = data.price * data.units_sold;
    //     std::cout << data.bookID << " " << data.units_sold << " " 
    //             << data.revenue << " " << data.price << std::endl;
    // }

    // 1.21
    // My_Sales_Data data1, data2;
    // double revenue_sum = 0;
    // unsigned int units_sold_sum = 0;
    // std::cin >> data1.bookID >> data1.units_sold >> data1.price;
    // data1.revenue = data1.units_sold * data1.price;
    // std::cin >> data2.bookID >> data2.units_sold >> data2.price;
    // data2.revenue = data2.units_sold * data2.price;
    // if (data1.bookID == data1.bookID){
    //     revenue_sum = data1.revenue + data2.revenue;
    //     units_sold_sum = data1.units_sold + data2.units_sold;
    //     if (units_sold_sum != 0)
    //         std::cout << data1.bookID << " " << units_sold_sum << " " << 
    //         revenue_sum << " " << revenue_sum / units_sold_sum << std::endl;
    //     else
    //         std::cerr << "units_sold should not be 0" << std::endl;
    // } else {
    //     std::cerr << "book ID not same" << std::endl;
    // }

    // 1.22
    // My_Sales_Data data_sum, data;
    // if (std::cin >> data.bookID >> data.units_sold >> data.price){
    //     data.revenue = data.price * data.units_sold;
    //     data_sum = data;
    //     while (std::cin >> data.bookID >> data.units_sold >> data.price){
    //         data.revenue = data.price * data.units_sold;
    //         if (data.bookID == data_sum.bookID){
    //             data_sum.revenue += data.revenue;
    //             data_sum.units_sold += data.units_sold;
    //             data_sum.price = data_sum.revenue / data_sum.units_sold;
    //         } else {
    //             std::cout << data_sum.bookID << " " << data_sum.units_sold << " " << 
    //                     data_sum.revenue << " " << data_sum.price << std::endl;
    //             data_sum = data;
    //         }
    //     }
    //     std::cout << data_sum.bookID << " " << data_sum.units_sold << " " << 
    //             data_sum.revenue << " " << data_sum.price << std::endl;
    // }

    // 1.23
    My_Sales_Data data_prev, data;
    int cnt = 0;
    if (std::cin >> data.bookID >> data.units_sold >> data.price){
        data.revenue = data.price * data.units_sold;
        data_prev = data;
        cnt = 1;
        while (std::cin >> data.bookID >> data.units_sold >> data.price){
            data.revenue = data.price * data.units_sold;
            if (data.bookID == data_prev.bookID){
                cnt++;
                data_prev = data;
            } else {
                std::cout << data_prev.bookID << " " << cnt << std::endl;
                cnt = 1;
                data_prev = data;
            }
        }
        std::cout << data_prev.bookID << " " << cnt << std::endl;
    }

    return 0;
}
