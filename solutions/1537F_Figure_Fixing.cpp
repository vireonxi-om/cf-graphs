// Problem: Figure Fixing
// URL: https://codeforces.com/problemset/problem/1537/F
// Rating: 2200
// Tags: constructive algorithms, dfs and similar, dsu, graphs, greedy, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll v[210000], b[210000], c[210000];
vector<int> g[210000];
bool yes;

void dfs(int x, int y){
    if(!yes) return;
    for(auto u:g[x]){
        if(u==y) continue;
        if(c[u]>=0){
            if(c[u]==c[x]){ yes=false; break;}
            else continue;
        }
        c[u]=1-c[x];
        dfs(u, x);
    }
}

void solve(){
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){ c[i]=-1; g[i].clear();}
    ll sumt=0, sumv=0;
    for(int i=1; i<=n; i++){ scanf("%lld", &v[i]); sumv+=v[i];}
    for(int i=1; i<=n; i++){ scanf("%lld", &b[i]); sumt+=b[i];}
    int x, y;
    for(int i=1; i<=m; i++){
        scanf("%d%d", &x, &y);
        g[x].push_back(y); g[y].push_back(x);
    }
    bool can=true;
    if((sumv+sumt)%2) can=false;
    else{
        yes=true;
        c[1]=0;
        dfs(1, 0);
        if(yes){
            ll sum1=0, sum2=0;
            for(int i=1; i<=n; i++){
                if(c[i]==0) sum1+=(b[i]-v[i]);
                else sum2+=(b[i]-v[i]);
            }
            if(sum1!=sum2) can=false;
        }
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
