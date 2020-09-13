#include <cstdio>
#include <vector>
#include <algorithm>

int N;

struct Node
{
    int time, diff;

    bool operator<(const Node &o)
    {
        if (time != o.time)
            return time < o.time;
        return diff < o.diff;
    }
};

std::vector<Node> v;

void init()
{
    scanf("%d", &N);
    int s, t;
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &s, &t);
        v.push_back({s, 1});
        v.push_back({t, -1});
    }
}

void solve()
{
    int sum = 0;
    int res = 0;
    std::sort(v.begin(), v.end());
    for (int i = 0; i < 2 * N - 1; i++)
    {
        sum += v[i].diff;
        res = std::max(res, sum);
    }
    printf("%d\n", res);
}

int main(void)
{

    init();
    solve();

    return 0;
}