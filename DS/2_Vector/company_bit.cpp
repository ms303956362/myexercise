#include <cstdio>
#include "bitmap.h"

using CodeType = int;
class Codes: public Bitmap {
private:
    CodeType *codes;
public:
    Codes(Rank n = 0): Bitmap(n + 1) {
        codes = new Rank[n + 1];
    }

    ~Codes() {
        delete[] codes;
    }

    void logIn(Rank person, CodeType code) {
        set(person);
        codes[person] = code;
    }

    void logOut(Rank person) {
        clear(person);
    }

    void close() {
        reset();
    }

    CodeType queryCode(Rank person) {
        if (test(person))
            return codes[person];
        else
            return -1;
    }

    Rank queryNum() {
        return getNum();
    }
};


int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    Rank n;
    int m;
    scanf("%d %d", &n, &m);
    Codes codes(n);

    char input[1];
    Rank person;
    CodeType code;
    long long answer = 0;
    for (int i = 0; i != m; ++i) {
        scanf("%s", input);
        if (*input == 'I') {
            scanf("%d %d", &person, &code);
            codes.logIn(person, code);
        } else if (*input == 'O') {
            scanf("%d", &person);
            codes.logOut(person);
        } else if (*input == 'C') {
            codes.close();
        } else if (*input == 'N') {
            answer += codes.queryNum();
        } else if (*input == 'Q') {
            scanf("%d", &person);
            answer += codes.queryCode(person);
        }
    }
    printf("%lld", answer);
    return 0;
}
