// Problem: Trees and XOR Queries Again
// URL: https://codeforces.com/problemset/problem/1902/F
// Rating: 2400
// Tags: data structures, dfs and similar, divide and conquer, graphs, implementation, math, trees
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
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
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 210000;
const int M = (int)(1<<20);
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, q, a[N], dep[N], fa[N][30];
vector<int> fp[N], g[N];

struct xbase {
	int b[20];
}xb[N];

bool check(xbase bn, int num) {
	per(i, 0, 20) {
		if (num & (1 << i)) {
			if (bn.b[i] != 0) {
				num ^= bn.b[i];
			}
			else return true;
		}
	}
	return false;
}

xbase insert(xbase bn, int num) {
	per(i, 0, 20) {
		if (num & (1 << i)) {
			if (bn.b[i] != 0) {
				num ^= bn.b[i];
			}
			else {
				bn.b[i] = num;
				break;
			}
		}
	}
	return bn;
}

void dfs(int u, int v) {
	fa[u][0] = v;
	dep[u] = dep[fa[u][0]] + 1;
	for (int i = 1; i < 30; ++i) {
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	}
	
	//update fp and xb
	if (check(xb[v], a[u])) {
		xb[u] = insert(xb[v], a[u]);
		fp[u] = fp[v]; fp[u].pb(u);
	}
	else if (a[u]) {
		rep(i, 0, 20) xb[u].b[i] = 0;
		xb[u] = insert(xb[u], a[u]);
		int sz = fp[v].size();
		per(i, 0, sz) {
			int pt = fp[v][i];
			if (!check(xb[u], a[pt])) continue;
			xb[u] = insert(xb[u], a[pt]);
			fp[u].pb(pt);
		}
		reverse(fp[u].begin(),fp[u].end());
		fp[u].pb(u);
	}
	else {
		xb[u] = xb[v];
		fp[u] = fp[v];
	}
	
	for (auto x : g[u]) {
		if (x == v) continue;
		dfs(x, u);
	}
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	int tmp = dep[y] - dep[x], ans = 0;
	for (int j = 0; tmp; ++j, tmp >>= 1)
		if (tmp & 1) y = fa[y][j];
	if (y == x) return y;
	per(j, 0, 30) {
		if (fa[x][j] != fa[y][j]) {
			x = fa[x][j];
			y = fa[y][j];
		}
	}
	return fa[y][0];
}


int main() {
	IO;
	int x, y, k;
	cin >> n;
	repn(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	rep(i, 0, 20) xb[0].b[i] = 0;
	dfs(1, 0);
	cin >> q;
	repn(i, 1, q) {
		cin >> x >> y >> k;
		int lxy = lca(x, y);
		xbase xb_now;
		rep(i, 0, 20) xb_now.b[i] = 0;
		for (auto pt : fp[x]) {
			if (dep[pt] < dep[lxy]) continue;
			xb_now = insert(xb_now, a[pt]);
		}
		for (auto pt : fp[y]) {
			if (dep[pt] < dep[lxy]) continue;
			xb_now = insert(xb_now, a[pt]);
		}
		if (check(xb_now, k)) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}