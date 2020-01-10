# include <iostream>

int main(){
    // 1.9
    // int i = 50, sum = 0;
    // while(i<=100){
    //     sum += i;
    //     i++;
    // }
    // std::cout << "sum from 50 to 100 is " << sum << std::endl;
    

    //1.10
    // int val = 10;
    // while (val >= 0){
    //     std::cout << val << std::endl;
    //     val--;
    // }

    //1.11
    // int v1, v2, v_tmp;
    // std::cout << "Enter two integers: ";
    // std::cin >> v1 >> v2;
    // if (v1 > v2){
    //     v_tmp = v1;
    //     v1 = v2;
    //     v2 = v_tmp;
    // }
    // while (v1 <= v2){
    //     std::cout << v1 << " ";
    //     v1++;
    // }
    // std::cout << std::endl;
    
    //1.9 for
    // int sum = 0;
    // for (int i = 50; i <= 100;i++){
    //     sum += i;
    // }
    // std::cout << sum << std::endl;

    // //1.10 for
    // for (int i = 10; i >= 0;i--){
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    //1.11 for
    // int v1, v2, v_tmp;
    // std::cout << "Enter two integers: ";
    // std::cin >> v1 >> v2;
    // if (v1 > v2){
    //     v_tmp = v1;
    //     v1 = v2;
    //     v2 = v_tmp;
    // }
    // for (int i = v1; i <= v2;i++){
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    //1.16
    // int sum=0, val;
    // while (std::cin >> val)
    //     sum += val;
    // std::cout << "Sum of the numbers is " << sum << std::endl;

    //1.18
    int curval, val;
    if (std::cin >> curval){
        int cnt = 1;
        while (std::cin >> val){
            if (curval == val){
                cnt++;
            } else {
                std::cout << curval << " occurs " << cnt << " times" << std::endl;
                curval = val;
                cnt = 1;
            }
        }
        std::cout << curval << " occurs " << cnt << " times. " << std::endl;
    }


    return 0;
}