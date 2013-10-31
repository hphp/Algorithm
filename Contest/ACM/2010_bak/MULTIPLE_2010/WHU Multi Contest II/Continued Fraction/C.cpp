#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int max_n = 10000 + 10;

char steps[max_n];
int len[max_n];
vector<int> num;

bool solve();
void output_fraction();
void compute_numbers();
int get_length(int);
void output(char, int);

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%s", steps) == EOF)
        return false;
    output_fraction();
    return true;
}

void output_fraction() {
    compute_numbers();
    len[num.size() - 1] = -3;
    for (int i = num.size() - 2; i >= 0; --i)
        len[i] = len[i + 1] + get_length(num[i + 1]) + 3;
    int cnt = 0;
    for (int i = 0; i < num.size() - 1; ++i) {
        int tmp = get_length(num[i]) + 3;
        output(' ', cnt + tmp + len[i] - 1);
        puts("1");
        output(' ', cnt);
        printf("%d + ", num[i]);
        output('-', len[i]);
        puts("");
        cnt += tmp;
    }
    output(' ', cnt);
    printf("%d\n", num.back());
}

void compute_numbers() {
    num.clear();
    if (steps[0] == 'L')
        num.push_back(0);
    num.push_back(1);
    for (int i = 1; steps[i] != '\0'; ++i) {
        if (steps[i] == steps[i - 1])
            ++num.back();
        else
            num.push_back(1);
    }
    ++num.back();
}

int get_length(int k) {
    return k == 0 ? 1 : (int)log10(k + 1e-8) + 1;
}

void output(char c, int cnt) {
    for (; cnt > 0; --cnt)
        putchar(c);
}
