#include <cstdio>
#include <vector>
#include <algorithm>

int N, L;
std::vector<int> v;
void init()
{
    scanf("%d%d", &N, &L);
    int x;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        v.push_back(x);
    }
}

void solve()
{
    int cnt = 0;
    int cur = 0;
    std::sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        if (v[i] >= cur)
        {
            cur = v[i] + L;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}

int main(void)
{

    init();
    solve();

    return 0;
}