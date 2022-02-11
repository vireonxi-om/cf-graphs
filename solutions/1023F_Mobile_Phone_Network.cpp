// Problem: Mobile Phone Network
// URL: https://codeforces.com/problemset/problem/1023/F
// Rating: 2600
// Tags: dfs and similar, dsu, graphs, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 510000;
const int M = 5100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e17;

int n, k, m;
int id1[N], intree[N];
int dep[N], f[N], id[N];
vector<int> g[N];
PII a[N], b[N];
LL aw[N], bw[N];
map<PII, int> ed;

int find1(int i){
    return id1[i] == i ? i : id1[i] = find1(id1[i]);
}
int findf(int i){
    return id[i] == i ? i : id[i] = findf(id[i]);
}

void dfs(int u, int v){
    f[u] = v;
    dep[u] = dep[v] + 1;
    for(auto x: g[u]){
        if (x == v) continue;
        dfs(x, u);
    }
}

void work(int u, int v, int w){
    u = findf(u);
    v = findf(v);
    while(u != v){
        if(dep[u] >= dep[v]){
            auto it = ed.find(mp(min(u, f[u]), max(u, f[u])));
            if (it != ed.end()) aw[it->second] = w;
            id[u] = findf(f[u]); u = id[u];
        }
        else{
            auto it = ed.find(mp(min(v, f[v]), max(v, f[v])));
            if (it != ed.end()) aw[it->second] = w;
            id[v] = findf(f[v]); v = id[v];
        }
    }
}

int main(){
    IO;
    cin >> n >> k >> m;
    repn(i, 1, n){
        id1[i] = i; id[i] = i;
    }
    int fu, fv;
    repn(i, 1, k){
        cin >> a[i].fi >> a[i].se;
        if (a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        ed[a[i]] = i;
        fu = find1(a[i].fi); fv = find1(a[i].se);
        id1[fu] = fv;
        g[a[i].fi].pb(a[i].se); g[a[i].se].pb(a[i].fi);
    }
    repn(i, 1, m){
        cin >> b[i].fi >> b[i].se >> bw[i];
        fu = find1(b[i].fi); fv = find1(b[i].se);
        if (fu == fv) continue;
        intree[i] = 1; id1[fu] = fv;
        g[b[i].fi].pb(b[i].se); g[b[i].se].pb(b[i].fi);
    }
    dep[0] = 0;
    dfs(1, 0);
    repn(i, 1, k) aw[i] = INF;
    repn(i, 1, m) {
        if (intree[i]) continue;
        work(b[i].fi, b[i].se, bw[i]);
    }
    LL ans = 0;
    bool can = false;
    repn(i, 1, k) {
        if (aw[i] == INF) can = true;
        ans += aw[i];
    }
    if (can) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}

