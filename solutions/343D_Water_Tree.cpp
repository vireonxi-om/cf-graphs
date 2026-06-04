// Problem: Water Tree
// URL: https://codeforces.com/problemset/problem/343/D
// Rating: 2100
// Tags: data structures, dfs and similar, graphs, trees
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

int n, m;
LL sum[M], lz[M];


vector<int> g[N];
int sz[N], son[N], dfn[N], l[N], r[N], fat[N], arr[N], cnt;
int dep[N], f[N];
void dfs(int x, int fa) {
    sz[x] = 1;
    dep[x] = dep[fa] + 1;
    f[x] = fa;
    for (auto y: g[x]) {
        if (y != fa) {
            dfs(y, x);
            sz[x] += sz[y];
            if (sz[y] > sz[son[x]]) son[x] = y;
        }
    }
}
void dfs2(int x, int fa, int anc) {
    dfn[x] = ++cnt;
    arr[cnt] = x;
    fat[x] = anc;
    l[x] = cnt;
    if (son[x]) dfs2(son[x], x, anc);
    for (auto y: g[x]) {
        if (y != fa && y != son[x]) {
            dfs2(y, x, y);
        }
    }
    r[x] = cnt;
}
void pushdown(int k, int l, int r) {
    if (lz[k]!=-1) {
        sum[LC] = lz[k];
        lz[LC] = lz[k];
        sum[RC] = lz[k];
        lz[RC] = lz[k];
        lz[k] = -1;
    }
}
void change(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        sum[k] = c;
        lz[k] = c;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    if (b <= mid) change(LC, l, mid, a, b, c);
    else if (a > mid) change(RC, mid + 1, r, a, b, c);
    else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
}
LL ask(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return sum[k];
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    LL res = 0;
    if (b <= mid) res = ask(LC, l, mid, a, b);
    else if (a > mid) res = ask(RC, mid + 1, r, a, b);
    return res;
}
int main()
{
    IO;
    cin >> n;
    rep(i, 1, M) lz[i]=-1;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    dfs(1, 0);
    dfs2(1, 0, 1);
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 2) {
            int x, y = 1, z = 0;
            cin >> x;
            while (fat[x] != 1) {
                change(1, 1, n, dfn[fat[x]], dfn[x], z);
                x = f[fat[x]];
            }
            change(1, 1, n, dfn[1], dfn[x], z);
        }
        else if (op == 1) {
            int x;
            cin >> x;
            change(1, 1, n, l[x], r[x], 1);
        }
        else {
            int x;
            cin >> x;
            LL ans = ask(1, 1, n, dfn[x], dfn[x]);
            cout << ans << "\n";
        }
    }

    return 0;
}
