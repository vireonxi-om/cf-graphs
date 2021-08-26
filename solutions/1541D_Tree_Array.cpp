// Problem: Tree Array
// URL: https://codeforces.com/problemset/problem/1541/D
// Rating: 2300
// Tags: combinatorics, dp, graphs, math, probabilities, trees
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, fa[210], l[210];
ll a[210][210];
const ll M=1000000007;
vector<int> g[210];


ll extended_gcd(ll a,ll b,ll &x,ll &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    else{
        ll r=extended_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
ll inv(ll a,ll n){
    ll xx,yy;
    extended_gcd(a,n,xx,yy);
    return (xx%n+n)%n;
}

int lca(int x, int y){
    if(l[x]<l[y]) swap(x, y);
    while(l[x]>l[y]) x=fa[x];
    while(x!=y){
        x=fa[x]; y=fa[y];
    }
    return x;
}

void dfs(int u){
    for(auto x:g[u]){
        if(x==fa[u]) continue;
        l[x]=l[u]+1;
        fa[x]=u;
        dfs(x);
    }
}

int main(){
    scanf("%d", &n);
    int u, v;
    for(int i=1; i<n; i++){
        scanf("%d%d", &u, &v);
        g[u].push_back(v); g[v].push_back(u);
    }
    ll inv2=inv(2, M), invn=inv(n, M);
    for(int i=1; i<=n; i++) a[0][i]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            a[i][j]=(a[i][j-1]+a[i-1][j])*inv2;
            a[i][j]%=M;
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        fa[i]=i;
        l[u]=1;
        dfs(i);
        for(int x=1; x<=n; x++){
            for(int y=x+1; y<=n; y++){
                int k=lca(x, y);
                ans+=a[l[y]-l[k]][l[x]-l[k]];
                ans%=M;
            }
        }
    }
    ans*=invn; ans%=M;
    printf("%lld\n", ans);
    return 0;
}