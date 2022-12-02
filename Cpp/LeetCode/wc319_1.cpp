#include "usual.h"

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return vector<double>{celsius + 273.15, celsius * 1.80 + 32.00};
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
