// Problem: Annual Ants' Gathering
// URL: https://codeforces.com/problemset/problem/1949/C
// Rating: 1900
// Tags: dfs and similar, dp, greedy, trees
// Language: C++20 (GCC 13-64)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define eb emplace_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand


vector<int> g[N];
int n, dp[N], sz[N], f[N], v[N];
inline int lowbit(int x) {
    return x & -x;
}
int get(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += v[i];
    return res;
}
void add(int x, int y) {
    if (!x) return;
    for (int i = x; i <= n; i += lowbit(i)) v[i] += y;
}
int check(int num) {
    int cur = 1;
    while (1) {
        int last = cur;
        cur = get(cur);
        if (cur == last) break;
    }
    return cur == num;
}
void dfs(int x, int fa) {
    sz[x] = 1;
    vector<int> arr;
    arr.pb(1);
    int num = 0;
    for (auto y: g[x]) if (y != fa) {
        dfs(y, x);
        sz[x] += sz[y];
        arr.pb(sz[y]);
        if (!dp[y]) num++;
    }
    for (auto p: arr) add(p, p);
    if (num == 0 && check(sz[x])) dp[x] = 1;
    for (auto p: arr) add(p, -p);
}
void dfs2(int x, int fa) {
    add(n - sz[x], n - sz[x]);
    add(1, 1);
    int num = 0, pos;
    for (auto y: g[x]) if (y != fa) {
        add(sz[y], sz[y]);
        if (!dp[y]) num++, pos = y;
    }
    if (check(n) && num == 0) {
        cout << "YES\n";
        exit(0);
    }
    for (auto y: g[x]) if (y != fa) {
        add(sz[y], -sz[y]);
        if (check(n - sz[y]) && (num == 0 || num == 1 && pos == y)) f[y] = 1;
        add(sz[y], sz[y]);
    }
    add(n - sz[x], sz[x] - n), add(1, -1);
    for (auto y: g[x]) if (y != fa) add(sz[y], -sz[y]);
    for (auto y: g[x]) if (y != fa && f[y]) dfs2(y, x);
}
int main() {
    IO;
    cin >> n;
    rep(i, 1, n) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << "NO\n";
    return 0;
}
