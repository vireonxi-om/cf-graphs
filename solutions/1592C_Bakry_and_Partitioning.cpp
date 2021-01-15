// Problem: Bakry and Partitioning
// URL: https://codeforces.com/problemset/problem/1592/C
// Rating: 1700
// Tags: bitmasks, constructive algorithms, dfs and similar, dp, graphs, trees
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

const int N = 110000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, k, eqt[N];
LL t;
LL a[N], sub[N];
vector<int> g[N];
bool yes;
int cnt;

void dfs(int u, int v) {
    for (auto x: g[u]) {
        if (x == v) continue;
        dfs(x, u);
        sub[u] = (sub[u] ^ sub[x]);
        eqt[u] = (eqt[u] | eqt[x]);
    }
    sub[u] = (sub[u] ^ a[u]);
    if (sub[u] == t && eqt[u] == 0) cnt ++;
    if (sub[u] == t) eqt[u] = (eqt[u] | 1);
    if (eqt[u] && sub[u] == 0){
        yes = true;
    }
}

void solve(){
    scanf("%d%d", &n, &k);
    repn(i, 1, n) g[i].clear();
    t = 0;
    repn(i, 1, n){
        scanf("%lld", &a[i]);
        t = (t ^ a[i]);
    }
    int u, v;
    rep(i, 1, n) {
        scanf("%d%d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }
    if (t == 0) printf("YES\n");
    else if (k == 2) printf("NO\n");
    else {
        yes = false;
        repn(i, 1, n){ sub[i] = 0; eqt[i] = 0;}
        cnt = 0;
        dfs(1, 0);
        if (yes || cnt >= 2) printf("YES\n");
        else printf("NO\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
