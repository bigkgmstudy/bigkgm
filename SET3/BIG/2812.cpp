#include <cstdio>
#include <vector>
#include <stack>

int N, K, KK;
std::vector<int> v;

void init()
{
    scanf("%d%d", &N, &K);
    KK = K;
    char x;
    for (int i = 0; i < N; i++)
    {
        scanf(" %c", &x);
        v.push_back(x - '0');
    }
}

void solve()
{
    std::stack<int> st;
    st.push(v[0]);
    for (int i = 1; i < N; i++)
    {
        while(K > 0){
            if(st.empty()){
                break;
            }
            if(st.top() >= v[i]){
                break;
            }
            st.pop();
            K--;
        }
        st.push(v[i]);
    }
    std::stack<int> rev;
    while(!st.empty()){
        rev.push(st.top());
        st.pop();
    }
    for (int i = 0; i < N-KK; i++)
    {
        printf("%d", rev.top());
        rev.pop();
    }
}

int main(void)
{

    init();
    solve();

    return 0;
}