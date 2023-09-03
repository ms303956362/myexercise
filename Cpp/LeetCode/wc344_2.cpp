#include "usual.h"

class FrequencyTracker {
    vector<int> cnt_freq, cnt_num;
public:
    FrequencyTracker(): cnt_freq(5 * 100000 + 5), cnt_num(100005) {

    }
    
    void add(int number) {
        ++cnt_num[number];
        if (cnt_num[number] == 1) {
            ++cnt_freq[1];
        } else {
            --cnt_freq[cnt_num[number] - 1];
            ++cnt_freq[cnt_num[number]];
        }
    }
    
    void deleteOne(int number) {
        if (cnt_num[number] == 0) {
            return;
        }
        --cnt_freq[cnt_num[number]];
        --cnt_num[number];
        ++cnt_freq[cnt_num[number]];
    }
    
    bool hasFrequency(int frequency) {
        return cnt_freq[frequency] > 0;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
