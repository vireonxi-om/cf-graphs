// Problem: Illusions of the Desert
// URL: https://codeforces.com/problemset/problem/1575/I
// Rating: 2300
// Tags: data structures, trees
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

const int N = 310000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, m, root;
int a[N];
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

void update(int k) {
    sum[k] = (sum[LC] + sum[RC]);
}
void build(int k, int l, int r) {
    if (l == r) {
        sum[k] = a[arr[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(LC, l, mid);
    build(RC, mid + 1, r);
    update(k);
}
void pushdown(int k, int l, int r) {
    if (lz[k]) {
        int mid = (l + r) / 2;
        sum[LC] = (sum[LC] + (LL)(mid - l + 1) * lz[k]);
        lz[LC] = (lz[LC] + lz[k]);
        sum[RC] = (sum[RC] + (LL)(r - mid) * lz[k]);
        lz[RC]= (lz[RC] + lz[k]);
        lz[k] = 0;
    }
}
void change(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        sum[k] = (sum[k] + (LL)(r - l + 1) * c);
        lz[k] = (lz[k] + c);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    if (b <= mid) change(LC, l, mid, a, b, c);
    else if (a > mid) change(RC, mid + 1, r, a, b, c);
    else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
    update(k);
}
LL ask(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return sum[k];
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    LL res = 0;
    if (b <= mid) res = ask(LC, l, mid, a, b);
    else if (a > mid) res = ask(RC, mid + 1, r, a, b);
    else res = (ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b));
    update(k);
    return res;
}


int main()
{
    IO;
    cin >> n >> m;
    repn(i, 1, n) {
        cin >> a[i];
        if (a[i] < 0) a[i] = -a[i];
    }
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    root = 1;
    dfs(root, 0);
    dfs2(root, 0, root);
    build(1, 1, n);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, z;
            cin >> x >> z;
            if (z < 0) z = -z;
            z = z - a[x];
            a[x] += z;
            y = x;
            while (fat[x] != fat[y]) {
                if (dep[fat[y]] > dep[fat[x]]) change(1, 1, n, dfn[fat[y]], dfn[y], z), y = f[fat[y]];
                else change(1, 1, n, dfn[fat[x]], dfn[x], z), x = f[fat[x]];
            }
            change(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z);
        }
        else if (op == 2) {
            int x, y;
            cin >> x >> y;
            LL ans = 0, det = a[x] + a[y];
            if (x != y) {
                while (fat[x] != fat[y]) {
                    if (dep[fat[y]] > dep[fat[x]]) ans = (ans + ask(1, 1, n, dfn[fat[y]], dfn[y])), y = f[fat[y]];
                    else ans = (ans + ask(1, 1, n, dfn[fat[x]], dfn[x])), x = f[fat[x]];
                }
                ans = (ans + ask(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y])));
                ans *= 2; ans -= det;
            }
            cout << ans << "\n";
        }

    }

    return 0;
}