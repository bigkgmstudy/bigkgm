#include <cstdio>
#include <algorithm>

int N;
char seats[55];

void init(){
    scanf("%d",&N);
    scanf("%s",seats);
}

void solve(){
    double res = 1;
    for(int i = 0; i < N; i++){
        if(seats[i] == 'S'){
            res++;
        }else{
            res+=0.5;
        }
    }
    printf("%d\n",std::min((int)res,N));
}

int main(void){

    init();
    solve();

    return 0;
}