#include <cstdio>
#include <queue>

typedef long long int ll;

int main(void){

    ll N, M, a,b;
    scanf("%lld%lld", &N, &M);
    std::priority_queue<ll> pq;
    for(int i = 0; i < N; i++){
        scanf("%lld",&a);
        pq.push(-a);
    }

    for(int j = 0; j < M; j++){
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }

    a = 0;

    while(!pq.empty()){
        a -= pq.top();
        pq.pop();
    }

    printf("%lld",a);

    return 0;
}