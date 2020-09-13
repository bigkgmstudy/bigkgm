#include <cstdio>
#include <vector>
#include <algorithm>

int G, P;
std::vector<int> Gv;
bool docked[100001];

void init()
{
    scanf("%d%d", &G, &P);
    int x;
    for (int i = 0; i < P; i++)
    {
        scanf("%d", &x);
        Gv.push_back(x);
    }
}
void solve()
{
    int max = G;
    int res = 0;
    for (int i = 0; i < P; i++)
    {
        int j = std::min(max, Gv[i]);
        while (docked[j])
        {
            j--;
        }
        if (j > 0)
        {
            docked[j] = true;
            res++;
        } else {
            break;
        }
        while (docked[max])
        {
            max--;
        }
    }
    printf("%d\n", res);
}

int main(void)
{
    init();
    solve();
    return 0;
}