#include "usual.h"

using LL = long long;
const LL Max = 1005, mod = 1e9 + 7;
// https://blog.csdn.net/Gee_Zer/article/details/95920261
LL C[Max][Max];
bool Cok = false;
void Compare_C(){
    if (Cok) {
        return;
    }
    C[0][0]=1;
    for(int i=1;i<Max;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    Cok = true;
}

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int d = abs(endPos - startPos);
        if (k % 2 != d % 2 || d > k) {
            return 0;
        }
        Compare_C();
        return C[k][d];
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
