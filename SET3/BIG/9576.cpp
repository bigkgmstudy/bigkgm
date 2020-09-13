#include <cstdio>
#include <vector>

int C[2020][2020];
int F[2020][2020];
bool visited[2020];

int N, M, a, b;

bool dfs(int node, int maxFlow)
{
    if(node == 2002){
        return maxFlow;
    }
    if(visited[node]){
        return 0;
    }
    visited[node] = true;
    for(int i = 0; i <2020; i++){
        if(F[node][i] < C[node][i]){
            int flow = dfs(i, std::min(C[node][i] - F[node][i],maxFlow));
            if(flow > 0){
                F[node][i] += flow;
                F[i][node] -= flow;
                return true;
            }
        }
    }

    return false;
}

void init()
{
    for (int i = 0; i < 2020; i++)
    {
        std::fill_n(C[i], 2020, 0);
        std::fill_n(F[i], 2020, 0);
    }
    std::fill_n(visited, 2002, false);
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        C[i + 1000][2002] = 1;
    }
    for (int i = 1; i <= M; i++)
    {
        C[0][i] = 1;
        scanf("%d%d", &a, &b);
        for (int j = a; j <= b; j++)
        {
            C[i][j + 1000] = 1;
        }
    }
}

void solve()
{
    int res = 0;
    while (1)
    {
        std::fill_n(visited, 2002, false);
        int flow = dfs(0,2147483647);
        if(flow == 0)break;
        res+= flow;
    }
    printf("%d\n",res);
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