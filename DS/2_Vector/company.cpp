#include <cstdio>
#include <cstring>

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    int n, m;
    scanf("%d %d", &n, &m);
    int *codes= new int[n + 1];
    memset(codes, -1, (n + 1) * sizeof(int));
    int *persons = new int[m];
    
    char input[1];
    int person, code;
    int num = 0, k = 0;
    long long answer = 0;
    for (int i = 0; i != m; ++i) {
        scanf("%s", input);
        if (*input == 'I') {
            scanf("%d %d", &person, &code);
            if (codes[person] == -1){
                persons[k++] = person;
                ++num;
            }
            codes[person] = code;
        } else if (*input == 'O') {
            scanf("%d", &person);
            if (codes[person] != -1) {
                codes[person] = -1;
                --num;
            }
        } else if (*input == 'C') {
            for (int j = 0; j != k; ++j) { // 分摊复杂度O(1)
                codes[persons[j]] = -1;
            }
            k = 0;
            num = 0;
        } else if (*input == 'N') {
            answer += num;
        } else if (*input == 'Q') {
            scanf("%d", &person);
            answer += codes[person];
        }
    }
    printf("%lld", answer);
    return 0;
}
