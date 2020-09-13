#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

int N, K;

struct Jewel
{
    int m, v;

    bool operator<(const Jewel &o)
    {
        return m < o.m;
    }
};

std::vector<int> C;
std::vector<Jewel> J;

void init()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        Jewel jewel;
        scanf("%d%d", &jewel.m, &jewel.v);
        J.push_back(jewel);
    }
    for (int i = 0; i < K; i++)
    {
        int c;
        scanf("%d", &c);
        C.push_back(c);
    }
}
void solve()
{
    std::sort(J.begin(), J.end());
    std::sort(C.begin(), C.end());
    std::priority_queue<int> pq;

    int j = 0;
    long long res = 0;
    for(int i = 0; i < K; i++){
        while(j < N && J[j].m <= C[i]){
            pq.push(J[j].v);
            j++;
        }
        if(pq.empty())continue;
        res += pq.top();
        pq.pop();
    }
    printf("%lld\n",res);
}

int main(void)
{
    init();
    solve();

    return 0;
}