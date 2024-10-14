// Problem: Eye-Pleasing City Park Tour
// URL: https://codeforces.com/problemset/problem/1575/E
// Rating: 2600
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

const int N = 210000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, k, sum, root;
int a[N], son[N], f[N], pp[N];
vector<PII> g[N];
LL ans;
LL num[2][N], v[2][N];
inline int lowbit(int x) {
	return x & -x;
}
void add(LL v[], int x, LL y) {
	for (int i = x; i < N; i += lowbit(i)) {
		v[i] = (v[i] + y) % mod;
	}
}
LL get(LL v[], int x) {
	LL res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		res = (res + v[i]) % mod;
	}
	return res;
}
void getroot(int x,int fa) {
	son[x] = 1, f[x] = 0;
	for (auto p: g[x]) {
		int y = p.fi;
		if (!pp[y] && y != fa) {
			getroot(y, x);
			son[x] += son[y];
			f[x] = max(f[x], son[y]);
		}
	}
	f[x] = max(f[x], sum - son[x]);
	if (f[x] < f[root]) root = x;
}
void dfs(int x, int fa, int rcol, int col, int nu, LL sum, int tp) {
	sum = (sum + a[x]) % mod;
	if (tp == 0) {
		// same color
		if (k >= nu) {
			LL cnt = get(num[rcol], k - nu + 1);
			LL acc = get(v[rcol], k - nu + 1);
			ans = (ans + cnt * sum) % mod;
			ans = (ans + acc) % mod;
		}
		// different color
		if (k >= nu + 1) {
			LL cnt = get(num[rcol ^ 1], k - nu);
			LL acc = get(v[rcol ^ 1], k - nu);
			ans = (ans + cnt * sum) % mod;
			ans = (ans + acc) % mod;
		}
		if (nu <= k) ans = (ans + sum) % mod;
	}
	else if (tp == 1) {
		add(num[rcol], nu + 1, 1);
		add(v[rcol], nu + 1, sum);
	}
	else {
		add(num[rcol], nu + 1, mod - 1);
		add(v[rcol], nu + 1, mod - sum);
	}
	for (auto p: g[x]) {
		int y = p.fi, w = p.se;
		if (pp[y] || y == fa) continue;
		int nnu = nu;
		if (w != col) nnu++;
		dfs(y, x, rcol, w, nnu, sum, tp);
	}
}
void work(int x) {
	pp[x] = 1;
	for (auto p: g[x]) {
		int y = p.fi, w = p.se;
		if (!pp[y]) {
			dfs(y, x, w, w, 0, a[x], 0);
			dfs(y, x, w, w, 0, 0, 1);
		}
	}
	for (auto p: g[x]) {
		int y = p.fi, w = p.se;
		if (!pp[y]) {
			dfs(y, x, w, w, 0, 0, -1);
		}
	}
	for (auto p: g[x]) {
		int y = p.fi;
		if (!pp[y]) {
			root = 0, sum = son[y];
			getroot(y, 0);
			work(root);
		}
	}
}
int main()
{
	IO;
	cin >> n >> k;
	f[0] = sum = n;
	repn(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(y, w));
		g[y].pb(mp(x, w));
	}
	getroot(1, 0);
	work(root);
	repn(i, 1, n) {
		ans = (ans + a[i]) % mod;
	}
	cout << ans << endl;
	return 0;
}