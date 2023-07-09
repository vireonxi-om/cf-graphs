// Problem: Treelabeling
// URL: https://codeforces.com/problemset/problem/1605/D
// Rating: 2100
// Tags: bitmasks, constructive algorithms, dfs and similar, games, greedy, implementation, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)
 
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
 
const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;
 
int n, yes[N], f[N], ans[N];
vector<int> g[N];
int cnt;


void dfs(int u, int v) {
	if (yes[u]) cnt ++;
	for (auto x : g[u]) {
		if (x == v) continue;
		yes[x] = yes[u] ^ 1;
		dfs(x, u);
	}
}

void solve() {
	scanf("%d", &n);
	repn(i, 1, n){ g[i].clear(); yes[i] = 0; f[i] = 0;}
	cnt = 0;
	int u, v;
	repn(i, 1, n - 1) {
		scanf("%d%d", &u, &v);
		g[u].pb(v); g[v].pb(u);
	}
	yes[1] = 1;
	dfs(1, 0);
	if (cnt > n - cnt) {
		repn(i, 1, n) yes[i] = yes[i] ^ 1;
		cnt = n - cnt;
	}
	int now = 0, pos = 1;
	while (cnt) {
		if (cnt % 2) {
			int l = 1 << now;
			int r = 2 * l; 
			rep(i, l, r) {
				f[i] = 1; 
				while (pos <= n && !yes[pos]) pos ++;
				if (pos == n + 1) break;
				ans[pos] = i; pos ++;
			}
		}
		cnt /= 2;
		now ++;
	}
	pos = 1;
	repn(i, 1, n) {
		if (f[i]) continue;
		while (pos <= n && yes[pos]) pos ++;
		if (pos == n + 1) break;
		ans[pos] = i; pos ++;
	}
	repn(i, 1, n) printf("%d ", ans[i]); printf("\n");
}
 
int main() {
	int t;
	scanf("%d", &t);
	repn(i, 1, t) solve();
	return 0;
}
