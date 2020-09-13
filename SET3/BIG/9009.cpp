#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

int n;
std::vector<int> fib;

void initt()
{
    fib.push_back(0);
    fib.push_back(1);
    while (fib[fib.size() - 1] < 1000000000)
    {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }
}

void init()
{
    scanf("%d", &n);
}

void solve()
{
    std::stack<int> st;
    while (n > 0)
    {
        int toSubtr = fib[std::upper_bound(fib.begin(), fib.end(), n) - fib.begin()-1];
        st.push(toSubtr);
        n -= toSubtr;
    }

    while (!st.empty())
    {
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");
}

int main(void)
{
    int T;
    scanf("%d", &T);

    initt();

    while (T--)
    {
        init();
        solve();
    }
    return 0;
}