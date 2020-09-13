#include <cstdio>
#include <algorithm>

int N;
int L[10101];

void init()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &L[i]);
    }
}

void solve()
{
    std::sort(L, L + N);
    int max = 0;
    for (int i = 2; i < N; i++)
    {
        max = std::max(max, L[i] - L[i-2]);
    }
    max = std::max(max, L[N-1] - L[N-2]);
    printf("%d\n",max);
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        init();
        solve();
    }

    return 0;
}