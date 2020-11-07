#include  "usual.h"

class ParkingSystem {
    int capb;
    int capm;
    int caps;
    int currb;
    int currm;
    int currs;

public:
    ParkingSystem(int big, int medium, int small) {
        capb = big;
        capm = medium;
        caps = small;
        currb = 0;
        currm = 0;
        currs = 0;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (currb < capb) {
                ++currb;
                return true;
            } else {
                return false;
            }
        } else if (carType == 1) {
            if (currm < capm) {
                ++currm;
                return true;
            } else {
                return false;
            }
        } else {
            if (currs < caps) {
                ++currs;
                return true;
            } else {
                return false;
            }
        }
    }
};