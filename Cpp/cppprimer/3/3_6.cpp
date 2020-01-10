#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    
    // 3.43
    // int ia[3][4]={0,1,2,3,4,5,6,7,8,9,0,1};
    // cout << "range for" << endl;
    // for (int (&row)[4]: ia){
    //     for (int col: row)
    //         cout << col << " ";
    //     cout << endl;
    // }
    // cout << "index" << endl;
    // for (int i = 0; i != 3; ++i){
    //     for (int j = 0; j != 4; ++j)
    //         cout << ia[i][j] << " ";
    //     cout << endl;
    // }
    // cout << "pointer" << endl;
    // for (int(*p_row)[4] = ia; p_row != ia + 3;++p_row){
    //     for (int *p_col = *p_row; p_col != *p_row + 4; ++p_col)
    //         cout << *p_col << " ";
    //     cout << endl;
    // }

    // 3.44
    // int ia[3][4]={0,1,2,3,4,5,6,7,8,9,0,1};
    // using int_array = int[4];
    // for (int_array &row : ia){
    //     for (int col : row)
    //         cout << col << " ";
    //     cout << endl;
    // }
    // for (int_array *p_row = ia; p_row != ia + 3; ++p_row){
    //     for (int *p_col = *p_row; p_col != *p_row + 4; ++p_col)
    //         cout << *p_col << " ";
    //     cout << endl;
    // }

    // 3.45
    int ia[3][4]={0,1,2,3,4,5,6,7,8,9,0,1};
    for (auto &row : ia){
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }
    for (auto p_row = ia; p_row != ia + 3; ++p_row){
        for (auto p_col = *p_row; p_col != *p_row + 4; ++p_col)
            cout << *p_col << " ";
        cout << endl;
    }
    return 0;
}
