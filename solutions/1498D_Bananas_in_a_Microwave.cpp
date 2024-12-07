// Problem: Bananas in a Microwave
// URL: https://codeforces.com/problemset/problem/1498/D
// Rating: 2200
// Tags: dfs and similar, dp, graphs, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, cnt[110000], dp[110000];

int main(){
    scanf("%d%d", &n, &m);
    ll x;
    int t, y;
    dp[0]=0;
    for(int j=1; j<=m; j++) dp[j]=-1;
    for(int i=1; i<=n; i++){
        scanf("%d%lld%d", &t, &x, &y);
        for(int j=0; j<=m; j++) cnt[j]=0;
        if(t==1) x=(x+99999)/100000;
        for(int j=0; j<=m; j++){
            if(dp[j]==-1) continue;
            if(cnt[j]>=y) continue;
            if(t==1){
                ll nxt=j+x;
                if(nxt<=m && dp[nxt]==-1){
                    dp[nxt]=i;
                    cnt[nxt]=cnt[j]+1;
                }
            }
            else{
                ll nxt=ceil((double)j*x/100000);
                if(nxt<=m && dp[nxt]==-1){
                    dp[nxt]=i;
                    cnt[nxt]=cnt[j]+1;
                }
            }
        }
    }
    for(int i=1; i<=m; i++) printf("%d ", dp[i]); printf("\n");
    return 0;
}


