#include <cstdio>
#include <algorithm>

int L, P, V;

void init()
{
    scanf("%d%d%d", &L, &P, &V);
}

void solve(int t)
{
    printf("Case %d: %d\n", t, (V / P) * L + std::min(V % P, L));
}

int main(void)
{
    int t = 0;
    while (++t)
    {
        init();
        if (L == 0 && P == 0 && V == 0)
            break;
        solve(t);
    }

    return 0;
}