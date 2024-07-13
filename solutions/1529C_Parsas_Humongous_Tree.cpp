// Problem: Parsa's Humongous Tree
// URL: https://codeforces.com/problemset/problem/1529/C
// Rating: 1600
// Tags: dfs and similar, dp, graphs, greedy, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll l[110000], r[110000], dp[110000][2];
vector<int> g[110000];

void dfs(int u, int v){
    if(g[u].size()==1) return;
    for(auto x:g[u]){
        if(x==v) continue;
        dfs(x, u);
        dp[u][0]+=max(abs(l[u]-l[x])+dp[x][0], abs(l[u]-r[x])+dp[x][1]);
        dp[u][1]+=max(abs(r[u]-l[x])+dp[x][0], abs(r[u]-r[x])+dp[x][1]);
    }
}

void solve(){
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        g[i].clear();
        for(int j=0; j<=1; j++) dp[i][j]=0;
    }
    for(int i=1; i<=n; i++) scanf("%lld%lld", &l[i], &r[i]);
    int u, v;
    for(int i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    g[1].push_back(0);
    dfs(1, 0);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
