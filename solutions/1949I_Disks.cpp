// Problem: Disks
// URL: https://codeforces.com/problemset/problem/1949/I
// Rating: 1800
// Tags: dfs and similar, geometry, graph matchings, graphs
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((ull) new char);
#define rand Rand

int n, c[N], f[N], yes[N], cc[N][2];
vector<int> g[N];
LL x[N], y[N], r[N];
int cnt;

void dfs(int u, int v, int col) {
    c[u] = col;
    f[u] = cnt;
    for (auto x : g[u]) {
        if (f[x]) {
            if (c[x] == c[u]) {
                yes[f[u]] = -1;
            }
            continue;
        }
        dfs(x, u, 1 - col);
    }
}

int main() {
    IO;
    cin >> n;
    repn(i, 1, n) c[i] = -1;
    repn(i, 1, n){
        cin >> x[i] >> y[i] >> r[i];
    }
    repn(i, 1, n) {
        repn(j, i + 1, n) {
            LL len = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (len == (r[i] + r[j]) * (r[i] + r[j])) {
                g[i].pb(j); g[j].pb(i);
            }
        }
    }
    repn(i, 1, n) {
        if (f[i] > 0) continue;
        ++ cnt;
        dfs(i, 0, 0);
    }
    repn(i, 1, n) {
        cc[f[i]][c[i]] ++;
    }
    bool ans = false;
    repn(i, 1, cnt) {
        if (yes[i] < 0) continue;
        if (cc[i][0] != cc[i][1]) ans = true;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
