#include <iostream>
#include <string>
using namespace std;
#include <unordered_map>

class UndergroundSystem {
private:
    unordered_map<int, int> start_time;
    unordered_map<int, string> start_st;
    unordered_map<string, unordered_map<string, double>> table;
    unordered_map<string, unordered_map<string, int>> table_cnt;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start_time[id] = t;
        start_st[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        int st_t = start_time[id];
        string st_st = start_st[id];
        if (table_cnt[st_st].find(stationName) == table_cnt[st_st].end()) 
            table_cnt[st_st][stationName] = 1;
        else
            ++table_cnt[st_st][stationName];
        if (table[st_st].find(stationName) == table[st_st].end()) 
            table[st_st][stationName] = static_cast<double>(t - st_t);
        else
            table[st_st][stationName] += static_cast<double>(t - st_t);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return table[startStation][endStation] / table_cnt[startStation][endStation];
    }
};

int main(int argc, char const *argv[])
{
    UndergroundSystem undergroundSystem;
    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);
    cout << undergroundSystem.getAverageTime("Paradise", "Cambridge") << endl;       // 返回 14.0。从 "Paradise"（时刻 8）到 "Cambridge"(时刻 22)的行程只有一趟
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;          // 返回 11.0。总共有 2 躺从 "Leyton" 到 "Waterloo" 的行程，编号为 id=45 的乘客出发于 time=3 到达于 time=15，编号为 id=27 的乘客于 time=10 出发于 time=20 到达。所以平均时间为 ( (15-3) + (20-10) ) / 2 = 11.0
    undergroundSystem.checkIn(10, "Leyton", 24);
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;          // 返回 11.0
    undergroundSystem.checkOut(10, "Waterloo", 38);
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;          // 返回 12.0
    return 0;
}
